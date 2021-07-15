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

So now I ran this without the python marker API
I ran:
```
likwid-perfctr -C 0 -g FLOPS_DP python3 test_vec_likwid.py 
```

which gives me 
```
Group 1: FLOPS_DP
+------------------------------------------+---------+-------------+
|                   Event                  | Counter |  HWThread 0 |
+------------------------------------------+---------+-------------+
|             INSTR_RETIRED_ANY            |  FIXC0  | 17431825870 |
|           CPU_CLK_UNHALTED_CORE          |  FIXC1  |  9854596779 |
|           CPU_CLK_UNHALTED_REF           |  FIXC2  |  5695308696 |
| FP_ARITH_INST_RETIRED_128B_PACKED_DOUBLE |   PMC0  |        1178 |
|    FP_ARITH_INST_RETIRED_SCALAR_DOUBLE   |   PMC1  |     1426957 |
| FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE |   PMC2  |         586 |
| FP_ARITH_INST_RETIRED_512B_PACKED_DOUBLE |   PMC3  |     1884124 |
+------------------------------------------+---------+-------------+

+----------------------+------------+
|        Metric        | HWThread 0 |
+----------------------+------------+
|  Runtime (RDTSC) [s] |     3.1993 |
| Runtime unhalted [s] |     4.7037 |
|      Clock [MHz]     |  3625.0723 |
|          CPI         |     0.5653 |
|     DP [MFLOP/s]     |     5.1589 |
|   AVX DP [MFLOP/s]   |     4.7121 |
|  AVX512 DP [MFLOP/s] |     4.7114 |
|   Packed [MUOPS/s]   |     0.5895 |
|   Scalar [MUOPS/s]   |     0.4460 |
|  Vectorization ratio |    56.9265 |
+----------------------+------------+
```

