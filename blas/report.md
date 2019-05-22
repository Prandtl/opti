Different O levels
------------------
```
Ξ optimization/blas git:(master) ▶ icc blas-1.c -o blas-1.o -O0 && time ./blas-1.o
blas-1.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 10.932085 s.
./blas-1.o  10.94s user 0.05s system 99% cpu 11.011 total
Ξ optimization/blas git:(master) ▶ icc blas-1.c -o blas-1.o -O1 && time ./blas-1.o
blas-1.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 4.636713 s.
./blas-1.o  4.59s user 0.06s system 98% cpu 4.713 total
Ξ optimization/blas git:(master) ▶ icc blas-1.c -o blas-1.o -O2 && time ./blas-1.o
blas-1.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 4.270253 s.
./blas-1.o  4.27s user 0.05s system 99% cpu 4.346 total
Ξ optimization/blas git:(master) ▶ icc blas-1.c -o blas-1.o -O3 && time ./blas-1.o
blas-1.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 1.968587 s.
./blas-1.o  2.02s user 0.03s system 100% cpu 2.044 total
```

OpenMP For
==========
```
Ξ optimization/blas git:(master) ▶ icc blas-2.c -o blas-2.o -O3 -qopenmp && time ./blas-2.o
blas-2.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 1.573152 s.
./blas-2.o  6.12s user 0.11s system 376% cpu 1.654 total
```

BLAS
======
```
Ξ optimization/blas git:(master) ▶ icc blas-3.c -o blas-3.o -O3 -mkl && time ./blas-3.o
blas-3.c(15): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 0.052969 s.
./blas-3.o  0.11s user 0.16s system 182% cpu 0.145 total
```

Different O levels for double
============================
```
Ξ optimization/blas git:(master) ▶ icc blas-1d.c -o blas-1d.o -O0 && time ./blas-1d.o
blas-1d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 11.052700 s.
./blas-1d.o  11.09s user 0.03s system 99% cpu 11.130 total
Ξ optimization/blas git:(master) ▶ icc blas-1d.c -o blas-1d.o -O1 && time ./blas-1d.o
blas-1d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 4.715035 s.
./blas-1d.o  4.73s user 0.05s system 99% cpu 4.789 total
Ξ optimization/blas git:(master) ▶ icc blas-1d.c -o blas-1d.o -O2 && time ./blas-1d.o
blas-1d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 3.710170 s.
./blas-1d.o  3.66s user 0.12s system 99% cpu 3.787 total
Ξ optimization/blas git:(master) ▶ icc blas-1d.c -o blas-1d.o -O3 && time ./blas-1d.o
blas-1d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 2.013169 s.
./blas-1d.o  2.03s user 0.05s system 99% cpu 2.088 total
```

OpenMP parallel for double
=======================
```
Ξ optimization/blas git:(master) ▶ icc blas-2d.c -o blas-2d.o -O3 -qopenmp && time ./blas-2d.o
blas-2d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 1.868712 s.
./blas-2d.o  7.28s user 0.11s system 377% cpu 1.960 total
Ξ optimization/blas git:(master) ▶ icc blas-2d.c -o blas-2d.o -O3 && time ./blas-2d.o
blas-2d.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

blas-2d.c(47): warning #3180: unrecognized OpenMP #pragma
      #pragma omp parallel for num_threads(4)
      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 2.609258 s.
./blas-2d.o  2.64s user 0.05s system 99% cpu 2.698 total
```

DGEMM
=====
```
Ξ optimization/blas git:(master) ▶ icc blas-3d.c -o blas-3d.o -O3 -mkl && time ./blas-3d.o
blas-3d.c(15): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 0.076725 s.
./blas-3d.o  0.16s user 0.22s system 203% cpu 0.184 total
```