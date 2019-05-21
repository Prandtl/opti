```
optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o
omp.c(22): warning #3180: unrecognized OpenMP #pragma
      #pragma omp parallel for reduction(+:sum)
      ^

Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000
calculation took 0.000013 s.
sum: 5366
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
10000
calculation took 0.000084 s.
sum: 77187
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.009101 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o -qopenmp
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.009840 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o -qopenmp
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.010507 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o -qopenmp
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.011284 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.011353 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.009164 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o -qopenmp
Ξ optimization/omp-3 git:(master) ▶ 1000000
zsh: command not found: 1000000
↑127 optimization/omp-3 git:(master) ▶ icc omp.c -o omp.o -qopenmp
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.010236 s.
sum: 12300120
Ξ optimization/omp-3 git:(master) ▶ ./omp.o
Enter the number
1000000
calculation took 0.009781 s.
sum: 12300120
```