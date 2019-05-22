#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define X 10000
#define THREAD_NUM 8

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
    int chunkSize = X / THREAD_NUM;

#pragma omp parallel num_threads(THREAD_NUM)
    {
        int thread_num = omp_get_thread_num();

        int start = chunkSize * thread_num;
        int end = chunkSize * (thread_num + 1);
        // printf("%d: %d - %d\n", thread_num, start, end - 1);

        for (int i = start + 1; i < end; i++)
        {
            float multiplicator = A[i * X + i - 1] / A[(i - 1) * X + i - 1];
            A[i * X + i - 1] = 0;
            A[i * X + i] = A[i * X + i] - A[(i - 1) * X + i] * multiplicator;
            f[i] = f[i] - f[i - 1] * multiplicator;
            if (thread_num != 0)
            {
                A[i * X + start - 1] = -A[(i - 1) * X + start - 1] * multiplicator;
            }
        }

#pragma omp barrier

        for (int i = end - 2; i >= start && i > 0; i--)
        {
            float multiplicator = A[(i - 1) * X + i] / A[i * X + i];
            A[(i - 1) * X + start - 1] = A[(i - 1) * X + start - 1] - A[i * X + start - 1] * multiplicator;
            A[(i - 1) * X + i - 1] = A[(i - 1) * X + i - 1] - A[i * X + i - 1] * multiplicator;
            A[(i - 1) * X + i] = 0;
            A[(i - 1) * X + end - 1] = A[(i - 1) * X + end - 1] - A[i * X + end - 1] * multiplicator;
            f[i - 1] = f[i - 1] - f[i] * multiplicator;
        }

#pragma omp single
        {

            for (int i = chunkSize * 2 - 1; i < X; i = i + chunkSize)
            {
                float multiplicator = A[i * X + i - chunkSize] / A[(i - chunkSize) * X + i - chunkSize];
                A[i * X + i - chunkSize] = 0;
                A[i * X + i] = A[i * X + i] - A[(i - chunkSize) * X + i] * multiplicator;
                f[i] = f[i] - f[i - 1] * multiplicator;
            }

            f[X - 1] = f[X - 1] / A[(X - 1) * X + X - 1];
            A[(X - 1) * X + X - 1] = 1;

            for (int i = X - chunkSize - 1; i > 0; i = i - chunkSize)
            {
                f[i] = (f[i] - A[i * X + i + chunkSize] * f[i + chunkSize]) / A[i * X + i];
                A[i * X + i] = 1;
                A[i * X + i + chunkSize] = 0;
            }
        }

        // print_matrice(A, X, X);
        // printf("\n");
        // print_matrice(f, 1, X);
        for (int i = start; i < end - 1; i++)
        {
            if (thread_num == 0)
            {
                f[i] = (f[i] - A[i * X + chunkSize - 1] * f[start + chunkSize - 1]) / A[i * X + i];
                A[i * X + chunkSize - 1] = 0;
                A[i * X + i] = 1;
            }
            else
            {
                f[i] = (f[i] - A[i * X + chunkSize - 1] * f[start + chunkSize - 1] - A[i * X + start - 1] * f[start - 1]) / A[i * X + i];
                A[i * X + start + chunkSize - 1] = 0;
                A[i * X + start - 1] = 0;
                A[i * X + i] = 1;
            }
        }
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