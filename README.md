# Testing likwid on Firedrake kernels which are vectorised

The following Firedrake status is needed. The `*-kokismachine` branches live on my forks
https://github.com/sv2518/firedrake and https://github.com/sv2518/PyOP2
```
---------------------------------------------------------------------------
|Package             |Branch                        |Revision  |Modified  |
---------------------------------------------------------------------------
|COFFEE              |master                        |70c1e66   |False     |
|FInAT               |HEAD                          |273d570   |False     |
|PyOP2               |batched-blas-matfree-kokismachine|a6e16384  |False     |
|fiat                |HEAD                          |1d562d6   |False     |
|firedrake           |tsslac-batchedblas-kokismachine|8077a9cc  |False     |
|h5py                |firedrake                     |78531f08  |False     |
|libspatialindex     |master                        |4768bf3   |True      |
|libsupermesh        |master                        |5827e88   |False     |
|loopy               |cvec-batched-blas             |9e4aebc9  |False     |
|petsc               |firedrake                     |e85aaad7c1|False     |
|pyadjoint           |master                        |1c9c15c   |False     |
|tsfc                |local-matfree                 |264a07c   |False     |
|ufl                 |HEAD                          |e3b8752d  |False     |
---------------------------------------------------------------------------
```

The driver python file is test_vec_likwid.py. It's currently set up so that we
time action and action of form on rhs, where the problems is 
```
    mesh = BoxMesh(n,n,n,1,1,1)
    V = FunctionSpace(mesh, "DG", p)
    u = TrialFunction(V)
    v = TestFunction(V)
    lmbda = Constant(value)
    form = (dot(grad(v), grad(u)) + lmbda * v * u) * dx

    f = Function(V)
    f.assign(2.)
    rhs = inner(f, v) * dx
```

We need to double check what the AVX on COSMA the PyOP2 branch above is for avx512

On Kokis machine I struggled, because if I run something like:
```
likwid-perfctr -C 0 -g FLOPS_AVX -m testlkw.py
```
I get an error that says:
```
Warning: Counter PMC3 cannot be used if Restricted Transactional Memory feature is enabled and
         bit 0 of register TSX_FORCE_ABORT is 0. As workaround write 0x1 to TSX_FORCE_ABORT:
         sudo wrmsr 0x10f 0x1`
```
and the workaround does not work,
[UPDATE: sudo apt-get install msr-tools and then sudo wrmsr 0x10f 0x1 did the trick]

and also
```
Marker API result file does not exist. This may happen if the application has not called LIKWID_MARKER_CLOSE.
``` 
even though I close the marker region.
