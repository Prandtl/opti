Ξ optimization/automatic-1 git:(master) ▶ icc -parallel matrix.c -o matrix.o -qopt-report=5 -O2
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(71): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^
Ξ optimization/automatic-1 git:(master) ▶ time ./matrix.o
A.
        B.
                C.
starting multiplication
finished.
multiplication took 0 ticks
everything took 31437500 ticks
./matrix.o  23.12s user 8.33s system 99% cpu 31.522 total
Ξ optimization/automatic-1 git:(master) ▶ icc matrix.c -o matrix.o -qopt-report=5
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(71): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

Ξ optimization/automatic-1 git:(master) ▶ time ./matrix.o
A.
        B.
                C.
starting multiplication
finished.
multiplication took 0 ticks
everything took 33000000 ticks
./matrix.o  23.36s user 9.66s system 98% cpu 33.360 total
