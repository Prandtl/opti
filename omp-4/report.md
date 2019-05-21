Ξ optimization/omp-4 git:(master) ▶ icc omp.c -o omp.o
omp.c(45): warning #266: function "memset" declared implicitly
      memset(blockSieve, 0, number);
      ^

omp.c(49): warning #3180: unrecognized OpenMP #pragma
      #pragma omp parallel for reduction(+:counter)
      ^

Ξ optimization/omp-4 git:(master) ▶ ./omp.o
Enter the number
1000000000
initialization...
done.
sieving...
done.
sieving took 11.504518 s.
amount of primes: 50846696
Ξ optimization/omp-4 git:(master) ▶ icc omp.c -o omp.o -qopenmp
omp.c(45): warning #266: function "memset" declared implicitly
      memset(blockSieve, 0, number);
      ^

Ξ optimization/omp-4 git:(master) ▶ ./omp.o
Enter the number
1000000000
initialization...
done.
sieving...
done.
sieving took 6.029838 s.
amount of primes: 50846696