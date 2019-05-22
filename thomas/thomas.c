#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 10000

float *A, *f;

void generate_problem()
{
    int counter = 1;
    A[0] = counter++ % 25 + 1;
    A[1] = counter++ % 25 + 1;
    f[0] = 0;
    for (int i = 1; i < X - 1; i++)
    {
        A[i * X + i - 1] = counter++ % 25 + 1;
        A[i * X + i] = counter++ % 25 + 1;
        A[i * X + i + 1] = counter++ % 25 + 1;

        f[i] = i * i;
    }
    A[(X - 1) * X + X - 2] = counter++ % 25 + 1;
    A[(X - 1) * X + X - 1] = counter++ % 25 + 1;
    f[X - 1] = (X - 1) * (X - 1) % 25 + 1;
}

void print_matrice(float M[], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%lf ", M[c * i + j]);
        }
        printf("\n");
    }
}

void solve()
{
    for (int i = 1; i < X; i++)
    {
        float multiplicator = A[i * X + i - 1] / A[(i - 1) * X + i - 1];
        A[i * X + i - 1] = 0;
        A[i * X + i] = A[i * X + i] - multiplicator * A[(i - 1) * X + i];
        f[i] = f[i] - multiplicator * f[i - 1];
    }

    f[X - 1] = f[X - 1] / A[(X - 1) * X + X - 1];
    A[(X - 1) * X + X - 1] = 1;
    for (int i = X - 2; i >= 0; i--)
    {
        f[i] = (f[i] - A[i * X + i + 1] * f[i + 1]) / A[i * X + i];
        A[i * X + i] = 1;
        A[i * X + i + 1] = 0;
    }
}

void main()
{
    A = (float *)malloc(X * X * sizeof(float));
    printf("A x = ");
    f = (float *)malloc(X * sizeof(float));
    printf("f.\n");

    clock_t c0, c1, c2;
    double seconds;
    c0 = clock();
    generate_problem();

    // print_matrice(A, X, X);
    // print_matrice(f, X, 1);

    printf("starting calculation\n");
    c1 = clock();
    solve();
    c2 = clock();
    printf("finished.\n");

    // print_matrice(A, X, X);
    print_matrice(f, 1, X);
    int cpu_time_used = (c2 - c1);
    int cpu_time_used_all = (c2 - c0);
    printf("calculation took %i ticks\n", cpu_time_used);
    printf("everything took %i ticks\n", cpu_time_used_all);

    free(A);
    free(f);
}
