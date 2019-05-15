


Notes
=====

Почему с флагом -guided-par не меняется *.o?
При этом guided-par меняет содержание отчета: без него у matrice_multiply нет ничего связанного с параллелизацией циклов

Pragma/No-Pragma
================

↑130 optimization/automatic-1 git:(master) ▶ icc -parallel matrix-no-pragma.c -o matrix-no-pragma.o -qopt-report=5 -O2
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix-no-pragma.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix-no-pragma.c(68): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

Ξ optimization/automatic-1 git:(master) ▶ ./matrix-no-pragma.o
A.
        B.
                C.
starting multiplication
negative
finished.
multiplication took 3875000 ticks
everything took 3921875 ticks
Ξ optimization/automatic-1 git:(master) ▶ icc -parallel matrix.c -o matrix.o -qopt-report=5 -O2
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(70): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

Ξ optimization/automatic-1 git:(master) ▶ ./matrix.o
A.
        B.
                C.
starting multiplication
negative
finished.
multiplication took 4218750 ticks
everything took 4250000 ticks
Ξ optimization/automatic-1 git:(master) ▶ icc matrix.c -o matrix.o -qopt-report=5 -O2
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(70): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

Ξ optimization/automatic-1 git:(master) ▶ ./matrix.o
A.
        B.
                C.
starting multiplication
positive
finished.
multiplication took 1140625 ticks
everything took 1156250 ticks
Ξ optimization/automatic-1 git:(master) ▶ ./matrix-noparallel.o
A.
        B.
                C.
starting multiplication
positive
finished.
multiplication took 7765625 ticks
everything took 7812500 ticks


matrices 2000 * 10000 * 5000
============================

Ξ optimization/automatic-1 git:(master) ▶ ./matrix.o
A.
        B.
                C.
starting multiplication
positive
finished.
multiplication took 1359906250 ticks
everything took 1361046875 ticks
Ξ optimization/automatic-1 git:(master) ▶ icc -no-vec matrix.c -o matrix.o -O2 -qopt-report=5 && ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(70): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

A.
        B.
                C.
starting multiplication
positive
finished.
multiplication took 721062500 ticks
everything took 722171875 ticks


matrices 2000 * 2000 * 2000
=============================
Ξ optimization/automatic-1 git:(master) ▶ icc -parallel -no-vec matrix.c -o matrix.o -O2 -qopt-report=5 && ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(70): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

A.
        B.
                C.
starting multiplication
positive
finished.
multiplication took 73906250 ticks
everything took 74031250 ticks
Ξ optimization/automatic-1 git:(master) ▶ icc -no-vec matrix.c -o matrix.o -O2 -qopt-report=5 && ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(70): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

A.
        B.
                C.
starting multiplication
negative
finished.
multiplication took 38140625 ticks
everything took 38312500 ticks

Buffer
===========
Ξ optimization/automatic-1 git:(master) ▶ icc -no-vec matrix.c -o matrix.o -O2 -qopt-report=5 && time ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(60): warning #266: function "memcpy" declared implicitly
          memcpy(&C[z * i], buffer, z * sizeof(float));
          ^

matrix.c(74): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 39296875 ticks
everything took 39406250 ticks
./matrix.o  39.27s user 0.16s system 99% cpu 39.500 total
Ξ optimization/automatic-1 git:(master) ▶ icc -parallel -no-vec matrix.c -o matrix.o -O2 -qopt-report=5 && time ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(13): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(60): warning #266: function "memcpy" declared implicitly
          memcpy(&C[z * i], buffer, z * sizeof(float));
          ^

matrix.c(74): warning #266: function "clock" declared implicitly
      c0 = clock();
           ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 74468750 ticks
everything took 74593750 ticks
./matrix.o  74.59s user 0.14s system 734% cpu 10.171 total




THE MOMENT I REALISED THAT CLOCK AND TIME WERE LYING TO ME
===============================================================
Ξ optimization/automatic-1 git:(master) ▶ icc matrix.c -o matrix.o -O2 -qopt-report=5 && time ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(61): warning #266: function "memcpy" declared implicitly
          memcpy(&C[z * i], buffer, z * sizeof(float));
          ^

A.
        B.
                C.
starting multiplication
finished.
negative
multiplication took 37.974070 s.
./matrix.o  38.05s user 0.06s system 99% cpu 38.138 total
Ξ optimization/automatic-1 git:(master) ▶ icc -parallel matrix.c -o matrix.o -O2 -qopt-report=5 && time ./matrix.o
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
matrix.c(14): warning #266: function "time" declared implicitly
      srand((unsigned)time(&t));
                      ^

matrix.c(61): warning #266: function "memcpy" declared implicitly
          memcpy(&C[z * i], buffer, z * sizeof(float));
          ^

A.
        B.
                C.
starting multiplication
finished.
positive
multiplication took 10.104666 s.
./matrix.o  75.12s user 0.17s system 733% cpu 10.264 total


RESUME
========

В общем - parallel - работает.
наличие буфера - ничего не меняет, как вообщем-то и #pragma parallel: loop автопараллелизуется и без вмешательства человека