Initial
==========
```
Ξ optimization/thomas git:(master) ▶ icc thomas.c -o thomas.o && time ./thomas.o
A x = f.
starting calculation
finished.
0.349513, -0.524270, 0.749513, 0.240534, -0.034685, 1.028096, -0.997103, 0.670267, 1.341299, -4.439261,
...
-3.096792, 0.680897, 2.289636, -0.465247, 4.093905, -0.221850, -2.059193, 2.517488, 0.369927, -2.212550, 2.203694,
calculation took 0.000000 s
everything took 0.060643 s
./thomas.o  0.02s user 0.06s system 80% cpu 0.097 total
Ξ optimization/thomas git:(master) ▶ icc thomas.1.c -o thomas.1.o -qopenmp && time ./thomas.1.o
starting calculation
finished.
0.349514, -0.524270, 0.749514, 0.240534, -0.034685, 1.028096, -0.997103, 0.670267, 1.341299, -4.439263,
...
-5.869529, -0.501885, 6.172885, 0.514894, 0.198218, 3.506334, -2.738787, -0.163787, 3.864241, -3.368678, 0.086957,
calculation took 0.000000 s
everything took 0.007741 s
./thomas.1.o  0.00s user 0.02s system 40% cpu 0.039 total
```

after fixes
==========
```
↑130 optimization/thomas git:(master) ▶ icc thomas.1.c -o thomas.1.o -qopenmp -O3 -parallel && time ./thomas.1.o
starting calculation
finished.
0.387253, -0.580880, 1.251957, -1.291732, 2.581723, -2.443691, 2.581175, -2.081573, 3.204393, -3.647296,
...
4.510127, -3.140447, 2.459533, -1.392664, 1.780756, -0.482610, 0.045761, 0.419831, -0.033136, 0.120069, -0.000050,
calculation took 0.000000 s
everything took 0.006609 s
./thomas.1.o  0.00s user 0.03s system 103% cpu 0.030 total
Ξ optimization/thomas git:(master) ▶ icc thomas.c -o thomas.o && time ./thomas.o
A x = f.
starting calculation
finished.
0.387253, -0.580880, 1.251958, -1.291732, 2.581724, -2.443691, 2.581176, -2.081573, 3.204393, -3.647296,
...
4.510127, -3.140447, 2.459533, -1.392665, 1.780757, -0.482610, 0.045761, 0.419831, -0.033136, 0.120069, -0.000050,
calculation took 0.000000 s
everything took 0.057419 s
./thomas.o  0.02s user 0.05s system 67% cpu 0.093 total
```