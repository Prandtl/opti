Algorithm itself
===================
```
Ξ optimization/automatic-2 git:(master) ▶ icc sieve.c -o sieve.o
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
100
initialization...
done.
sieving...
done.
sieving took 0.000001 s.
amount of primes: 25
```

After using -parallel
=====================
guide-par предложил добавить прагмы к циклам, создания массива и финального прохода для подсчета количества простых чисел

в отчёте было сказано, что основной цикл содержит зависимости

After dependency removal
========================

После оптимизации зависимости исчезли, guide-par предложил навесить на основной цикл прагму

вот такой результат после добавления прагм:
```
Ξ optimization/automatic-2 git:(master) ▶ icc sieve.c -o sieve.o -O2 -qopt-report=5
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.114192 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.121212 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.119380 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.117133 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.134815 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ icc sieve.c -o sieve.o -O2 -qopt-report=5 -parallel
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.126288 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.135855 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.122167 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.143372 s.
amount of primes: 664579
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000
initialization...
done.
sieving...
done.
sieving took 0.126556 s.
amount of primes: 664579
```

На больших значениях виден небольшой выигрыш во времени:

```
Ξ optimization/automatic-2 git:(master) ▶ icc sieve.c -o sieve.o -O2 -qopt-report=5
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 25.178064 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 24.194153 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 24.137817 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 26.220132 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 24.250207 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ icc sieve.c -o sieve.o -O2 -qopt-report=5 -parallel
icc: remark #10397: optimization reports are generated in *.optrpt files in the output location
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 24.106295 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 23.701832 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 22.112621 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 23.696129 s.
amount of primes: 70462980
Ξ optimization/automatic-2 git:(master) ▶ ./sieve.o
Enter the number
10000000000
initialization...
done.
sieving...
done.
sieving took 22.534095 s.
amount of primes: 70462980
```
Такой небольшой прирост можно объяснить тем, что все потоки пишут и обращаются для проверки к одному и тому же массиву, это ведёт к постоянным синхронизациям