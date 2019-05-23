#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <math.h>

#define X 1000000

double *a, *b, *c, *f, *ai, *bi, *ci, *fi;

void generate_problem()
{
    int counter = 1;
    b[0] = counter++ % 25 + 1;
    c[0] = counter++ % 25 + 1;
    f[0] = 0;
    for (int i = 1; i < X - 1; i++)
    {
        a[i] = counter++ % 25 + 1;
        b[i] = counter++ % 25 + 1;
        c[i] = a[i] + b[i] + 1;
        f[i] = fmod(sin(i) * i, 25) + 1;
    }
    a[X - 1] = counter++ % 25 + 1;
    c[X - 1] = counter++ + 1;
    f[X - 1] = fmod(sin(X - 1) * (X - 1), 25) + 1;
}

void print_tridiagonal_matrice()
{
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
                        printf("0\t\t");
                    }
                }
            }
        }
        printf("\n");
    }
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

    for (int i = 1; i < X; i++)
    {
        double multiplicator = a[i] / c[i - 1];
        a[i] = 0;
        c[i] = c[i] - multiplicator * b[i - 1];
        f[i] = f[i] - multiplicator * f[i - 1];
    }

    f[X - 1] = f[X - 1] / c[X - 1];
    a[X - 1] = 1;
    for (int i = X - 2; i >= 0; i--)
    {
        f[i] = (f[i] - b[i] * f[i + 1]) / c[i];
        c[i] = 1;
        b[i] = 0;
    }
}

void main()
{
    a = (double *)malloc(X * sizeof(double));
    b = (double *)malloc(X * sizeof(double));
    c = (double *)malloc(X * sizeof(double));
    f = (double *)malloc(X * sizeof(double));

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
    free(f);
}
