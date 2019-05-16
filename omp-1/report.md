```
Ξ optimization/omp-1 git:(master) ▶ icc omp.c -o omp.o
omp.c(18): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

omp.c(29): warning #3180: unrecognized OpenMP #pragma
      #pragma omp parallel
      ^

omp.c(31): warning #3180: unrecognized OpenMP #pragma
          #pragma omp for
          ^

Ξ optimization/omp-1 git:(master) ▶ ./omp.o
Enter the number
100000000
calculation took 0.119462 s.
first one is more than 1k
Ξ optimization/omp-1 git:(master) ▶ icc omp.c -o omp.o -openmp
icc: command line error: option '-openmp' is not supported. Please use the replacement option '-qopenmp'
↑1 optimization/omp-1 git:(master) ▶ icc omp.c -o omp.o -qopenmp
omp.c(18): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

Ξ optimization/omp-1 git:(master) ▶ ./omp.o
Enter the number
100000000
calculation took 0.043099 s.
first one is more than 1k
```