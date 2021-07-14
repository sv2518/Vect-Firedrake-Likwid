import numpy as np
import time
import os, sys
import loopy
from tempfile import gettempdir
import contextlib
import importlib
from firedrake import *
import pyop2


def clean():
    os.system('firedrake-clean')
    # os.system('rm -r ' + gettempdir() +'/pyop2-cache-*')
    # from pyop2.op2 import exit
    # exit()

def check_inverse():
    mesh = BoxMesh(2,2,2,1,1,1)
    V = FunctionSpace(mesh, "DG", 2)
    u = TrialFunction(V)
    v = TestFunction(V)
    c = Tensor(v * u * dx)
    check = c.inv * c
    result = assemble(check)
    assert (result.M.values - np.identity(V.node_count) <= 1e-13).all()
    clean()

def check_solve():
    mesh = BoxMesh(2,2,2,1,1,1)
    V = FunctionSpace(mesh, "DG", 2)
    u = TrialFunction(V)
    v = TestFunction(V)
    f = Function(V)
    f.assign(1.)
    rhs = inner(f,v)*dx
    lmbda = Constant(1.0)
    form = (dot(grad(v), grad(u)) + lmbda * v * u) * dx
    A = Tensor(form)
    B = Tensor(rhs)
    check = A.solve(B)

    check = assemble(check)
    assert (check.dat.data - f.dat.data <= 1e-13).all()
    clean()

def plain(n, p, value):
    mesh = BoxMesh(n,n,n,1,1,1)
    V = FunctionSpace(mesh, "DG", p)
    u = TrialFunction(V)
    v = TestFunction(V)
    lmbda = Constant(value)
    form = (dot(grad(v), grad(u)) + lmbda * v * u) * dx
    
    f = Function(V)
    f.assign(2.)
    rhs = inner(f, v) * dx
    return form, rhs, f, mesh.comm.allreduce(V.dof_count)

def inverse(n, p):
    form, _, f, dofs = plain(n, p, 1.)
    return Tensor(form).inv, AssembledVector(f), dofs

def mul(n, p):
    form1, _, f, dofs = plain(n, p, 12.) 
    form2, _, f, dofs = plain(n, p, 1.)
    A = Mul(Tensor(form1), Tensor(form1).T)
    f = Function(A.arg_function_spaces[1])
    f.assign(2.0)
    return A, AssembledVector(f), dofs 

def hybridpc_solve(n, p):
    # Create a mesh
    mesh = UnitSquareMesh(n, n)
    U = FunctionSpace(mesh, "RT", p)
    V = FunctionSpace(mesh, "DG", p-1)
    W = U * V
    sigma, u = TrialFunctions(W)
    tau, v = TestFunctions(W)
    n = FacetNormal(mesh)

    # Define the source function
    x, y = SpatialCoordinate(mesh)
    f = Function(V)
    f.interpolate(10*exp(-(pow(x - 0.5, 2) + pow(y - 0.5, 2)) / 0.02))

    # Define the variational forms
    a = (dot(sigma, tau) + div(tau) * u + v * div(sigma)) * dx
    L = -f * v * dx + Constant(0.0) * dot(tau, n) * (ds(3) + ds(4))

    # Compare hybridized solution with non-hybridized
    w = Function(W)
    bc1 = DirichletBC(W[0], as_vector([0.0, -sin(5*x)]), 1)
    bc2 = DirichletBC(W[0], as_vector([0.0, sin(5*y)]), 2)
    bcs = [bc1, bc2]

    matfree_params = {'mat_type': 'matfree',
                      'ksp_type': 'preonly',
                      'pc_type': 'python',
                      'pc_python_type': 'firedrake.HybridizationPC',
                      'hybridization': {'ksp_type': 'cg',
                                        'pc_type': 'none',
                                        'ksp_rtol': 1e-8,
                                        'mat_type': 'matfree'}}
    solve(a == L, w, bcs=bcs, solver_parameters=matfree_params)
    sigma_h, u_h = w.split()

    w2 = Function(W)
    aij_params = {'mat_type': 'matfree',
                  'ksp_type': 'preonly',
                  'pc_type': 'python',
                  'pc_python_type': 'firedrake.HybridizationPC',
                  'hybridization': {'ksp_type': 'cg',
                                    'pc_type': 'none',
                                    'ksp_rtol': 1e-8,
                                    'mat_type': 'aij'}}
    solve(a == L, w2, bcs=bcs, solver_parameters=aij_params)
    _sigma, _u = w2.split()

    # Return the L2 error
    sigma_err = errornorm(sigma_h, _sigma)
    u_err = errornorm(u_h, _u)

    assert sigma_err < 1e-8
    assert u_err < 1e-8

def matfree_solve(n, p):
    mesh = BoxMesh(n,n,n,1,1,1)
    V = FunctionSpace(mesh, "DG", p)
    u = TrialFunction(V)
    v = TestFunction(V)
    f = Function(V)
    f.assign(1.)
    lmbda = Constant(1.0)
    form = (dot(grad(v), grad(u)) + lmbda * v * u) * dx
    rhs = inner(f,v)*dx

    A = Tensor(form)
    print(A.shape)
    B = Tensor(rhs)
    C = A.solve(B, decomposition=None, matfree=True)
    return C

def solv(n, p):
    form, rhs, _, dofs = plain(n, p, 1.0)
    A = Tensor(form)
    B = Tensor(rhs)
    C = A.solve(B)
    return C, dofs

def timing(a, L):
    start_time = time.time()
    r = assemble(action(a, L))
    end = time.time() - start_time
    # print("...... for the inverse action: %s seconds" % (end))
    return end

def warmup(a, L):
    assemble(action(a, L))

def warmup_solve(a):
    A = assemble(a)

def timing_solve(a):
    start_time = time.time()
    assemble(a)
    end = time.time() - start_time
    # print("...... for the solve assemble: %s seconds" % (end))
    return end

def run(vect, batched, N, P):

    if batched:
        pyop2.configuration.reconfigure(batched_blas="true")
    if vect:
        pyop2.configuration.reconfigure(batched_blas="ve")
    
    ##### CHECKS
    # check_inverse()
    # check_solve()


    from collections import OrderedDict
    t_solv = OrderedDict()
    t_inv = OrderedDict()
    t_mul = OrderedDict()
    t_plain = OrderedDict()
    
    for n in N:
        t_inv_p = OrderedDict()
        t_solv_p = OrderedDict()
        t_mul_p = OrderedDict()
        t_plain_p = OrderedDict()
        for p in P:
            print("PPPPPPPP", p)
            # clean()
            # a = matfree_solve(n, p)
            # timing_solve(a)
            # hybridpc_solve(n,p)
            clean()
            a, _, L, dofs = plain(n, p, 1.0)
            warmup(a, L) 
            t_plain_p[p] = (timing(a, L), dofs)
            #clean()
            #a, L, dofs = mul(n, p)
            #warmup(a, L) 
            #t_mul_p[p] = (timing(a, L), dofs)

            #clean()
            #a, L, dofs = inverse(n, p)
            #warmup(a, L)
            #t_inv_p[p] = (timing(a, L), dofs)

            #clean()
           # a, dofs = solv(n, p)
           # warmup_solve(a)
           # t_solv_p[p] = (timing_solve(a), dofs)

        t_solv[n] = t_solv_p
        t_inv[n] = t_inv_p
        t_plain[n] = t_plain_p
        t_mul[n] = t_mul_p

    return t_plain

def write_to_file(vec, batched, t_plain, folder):
    
    with open('%s/vect%s_batched%s_plain.txt' % (folder, vec, batched), 'w') as f:
        for key1, value1 in t_plain.items():
            for key2, value2 in value1.items():
                v1, v2 = value2
                f.write("(%d, %d, %f, %f)\n" % (key1, key2, v1, v2))

PETSc.Sys.popErrorHandler()
folder = "testlikwid/"#"kokismachine/investigation/N"+sys.argv[4]+"/"+sys.argv[3]
print("Creating folder " + folder)
os.system("mkdir -p " + folder)
N = [20]#[int(sys.argv[4])]
P = [1]#list(map(int, sys.argv[5].strip('[]').split(',')))
vec = True# if sys.argv[1]=="TRUE" else False
batched = False #if sys.argv[2]=="TRUE" else False

import pylikwid
print(vec, batched, N, P)
pylikwid.markerinit()
pylikwid.markerthreadinit()
pylikwid.markerstartregion("run")
t_plain = run(vec, batched, N, P)
pylikwid.markerstopregion("run")
nr_events, eventlist, time, count = pylikwid.markergetregion("run")
for i, e in enumerate(eventlist):
    print(i, e)
pylikwid.markerclose()
write_to_file(vec, batched, t_plain, folder)
