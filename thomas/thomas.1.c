#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <math.h>

#define X 10000
#define THREAD_NUM 8

double *a, *b, *c, *d, *f, *g, *ai, *bi, *ci, *fi;

void generate_problem()
{
    int counter = 1;
    b[0] = counter++ % 25 + 1;
    c[0] = counter++ % 25 + 1;
    f[0] = 0;
    d[0] = 0;
    g[0] = 0;
    for (int i = 1; i < X - 1; i++)
    {
        a[i] = counter++ % 25 + 1;
        b[i] = counter++ % 25 + 1;
        c[i] = a[i] + b[i] + 1;
        f[i] = fmod(sin(i) * i, 25) + 1;
        d[i] = 0;
        g[i] = 0;
    }
    a[X - 1] = counter++ % 25 + 1;
    c[X - 1] = counter++ + 1;
    f[X - 1] = fmod(sin(X - 1) * (X - 1), 25) + 1;
    d[X - 1] = 0;
    g[X - 1] = 0;

    // int counter = 1;
    // b[0] = 1;
    // c[0] = 2;
    // f[0] = 1;
    // d[0] = 0;
    // g[0] = 0;
    // for (int i = 1; i < X - 1; i++)
    // {
    //     a[i] = 1;
    //     b[i] = 1;
    //     c[i] = 2;
    //     f[i] = i + 1;
    //     d[i] = 0;
    //     g[i] = 0;
    // }
    // a[X - 1] = 1;
    // c[X - 1] = 2;
    // f[X - 1] = X;
    // d[X - 1] = 0;
    // g[X - 1] = 0;
}

void print_initial_matrice()
{
    int i, j;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < X; j++)
        {
            if (j == i - 1)
            {
                printf("%f\t", ai[i]);
            }
            else
            {
                if (j == i)
                {
                    printf("%f\t", ci[i]);
                }
                else
                {
                    if (j == i + 1)
                    {
                        printf("%f\t", bi[i]);
                    }
                    else
                    {
                        printf("0\t\t");
                    }
                }
            }
        }
        printf("\n");
    }
}

void print_tridiagonal_matrice()
{
    int chunkSize = X / THREAD_NUM;
    int i, j;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < X; j++)
        {
            if (j == i - 1)
            {
                printf("%f\t", a[i]);
            }
            else
            {
                if (j == i)
                {
                    printf("%f\t", c[i]);
                }
                else
                {
                    if (j == i + 1)
                    {
                        printf("%f\t", b[i]);
                    }
                    else
                    {
                        if ((j + 1) % chunkSize == 0 && i <= j + chunkSize && i > j)
                        {
                            printf("%f\t", d[i]);
                        }
                        else
                        {
                            if ((j + 1) % chunkSize == 0 && i >= j - chunkSize && i < j)
                            {
                                printf("%f\t", g[i]);
                            }
                            else
                            {
                                printf("0\t\t");
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
}

void print_matrice(double M[], int r, int c)
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
        if (thread_num != 0)
        {
            d[start] = a[start];
        }
        for (int i = start + 1; i < end; i++)
        {
            double multiplicator = a[i] / c[i - 1];
            a[i] = 0;
            c[i] = c[i] - b[i - 1] * multiplicator;
            f[i] = f[i] - f[i - 1] * multiplicator;
            if (thread_num != 0)
            {
                d[i] = -d[i - 1] * multiplicator;
            }
        }

#pragma omp barrier
        g[end - 2] = b[end - 2];

        for (int i = end - 2; i > start && i > 0; i--)
        {
            double multiplicator = b[i - 1] / c[i];
            b[i - 1] = 0;
            if (i != start)
            {
                d[i - 1] = d[i - 1] - d[i] * multiplicator;
            }
            g[i - 1] = g[i - 1] - g[i] * multiplicator;
            f[i - 1] = f[i - 1] - f[i] * multiplicator;
        }

        if (thread_num != 0)
        {
            double multiplicator = b[start - 1] / c[start];
            a[start] = d[start];
            b[start - 1] = 0;
            c[start - 1] = c[start - 1] - a[start] * multiplicator;
            g[start - 1] = g[start - 1] - g[start] * multiplicator;
            f[start - 1] = f[start - 1] - f[start] * multiplicator;
        }

#pragma omp barrier
#pragma omp single
        {
            for (int i = chunkSize * 2 - 1; i < X; i = i + chunkSize)
            {
                double multiplicator = d[i] / c[i - chunkSize];
                d[i] = 0;
                c[i] = c[i] - g[i - chunkSize] * multiplicator;
                f[i] = f[i] - f[i - chunkSize] * multiplicator;
            }

            f[X - 1] = f[X - 1] / c[X - 1];
            c[X - 1] = 1;

            for (int i = X - chunkSize - 1; i > 0; i = i - chunkSize)
            {
                f[i] = (f[i] - g[i] * f[i + chunkSize]) / c[i];
                c[i] = 1;
                g[i] = 0;
            }
        }

        for (int i = start; i < end - 1; i++)
        {
            if (thread_num == 0)
            {
                f[i] = (f[i] - g[i] * f[chunkSize - 1]) / c[i];
                g[i] = 0;
                c[i] = 1;
            }
            else
            {
                f[i] = (f[i] - g[i] * f[start + chunkSize - 1] - d[i] * f[start - 1]) / c[i];
                g[i] = 0;
                d[i] = 0;
                c[i] = 1;
            }
        }
    }
}

void main()
{
    a = (double *)malloc(X * sizeof(double));
    b = (double *)malloc(X * sizeof(double));
    c = (double *)malloc(X * sizeof(double));
    d = (double *)malloc(X * sizeof(double));
    f = (double *)malloc(X * sizeof(double));
    g = (double *)malloc(X * sizeof(double));

    ai = (double *)malloc(X * sizeof(double));
    bi = (double *)malloc(X * sizeof(double));
    ci = (double *)malloc(X * sizeof(double));
    fi = (double *)malloc(X * sizeof(double));

    struct timeval start, middle, stop;
    double seconds;
    gettimeofday(&start, NULL);
    generate_problem();

    memcpy(ai, a, X * sizeof(double));
    memcpy(bi, b, X * sizeof(double));
    memcpy(ci, c, X * sizeof(double));
    memcpy(fi, f, X * sizeof(double));

    // print_tridiagonal_matrice();
    // print_matrice(f, X, 1);

    // printf("\n");

    // print_initial_matrice();
    // print_matrice(fi, X, 1);

    printf("starting calculation\n");
    gettimeofday(&middle, NULL);
    solve();
    gettimeofday(&stop, NULL);
    printf("finished.\n");

    // print_tridiagonal_matrice();
    // printf("\n");
    // print_matrice(d, X, 1);
    // printf("\n");
    // print_matrice(g, X, 1);
    // printf("\n");
    // print_matrice(f, X, 1);

    // printf("\n");

    // print_initial_matrice();
    // print_matrice(fi, X, 1);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%f, ", f[i]);
    // }
    // printf("\n...\n");
    // for (int i = X - 11; i < X; i++)
    // {
    //     printf("%f, ", f[i]);
    // }
    // printf("\n");

    double sum = 0;

    sum += fabs(f[0] * ci[0] + f[1] * bi[0] - fi[0]);
    for (int i = 1; i < X - 1; i++)
    {
        sum += fabs(f[i - 1] * ai[i] + f[i] * ci[i] + f[i + 1] * bi[i] - fi[i]);
        // printf("sum: %lf\n", sum);
    }
    sum += fabs(f[X - 2] * ai[X - 1] + f[X - 1] * ci[X - 1] - fi[X - 1]);

    printf("sum: %lf\n", sum);

    double all_time = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    double calculation_time = (double)(stop.tv_sec - middle.tv_sec + (stop.tv_usec - middle.tv_usec) / 1000000.0);
    printf("calculation took %lf s\n", calculation_time);
    printf("everything took %lf s\n", all_time);

    free(a);
    free(b);
    free(c);
    free(d);
    free(f);
    free(g);
}
