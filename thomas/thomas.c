#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

    struct timeval start, middle, stop;
    double seconds;
    gettimeofday(&start, NULL);
    generate_problem();

    // print_matrice(A, X, X);
    // print_matrice(f, X, 1);

    printf("starting calculation\n");
    gettimeofday(&middle, NULL);
    solve();
    gettimeofday(&stop, NULL);
    printf("finished.\n");

    // print_matrice(A, X, X);
    // print_matrice(f, 1, X);

    for (int i = 0; i < 10; i++)
    {
        printf("%f, ", f[i]);
    }
    printf("\n...\n");
    for (int i = X - 11; i < X; i++)
    {
        printf("%f, ", f[i]);
    }
    printf("\n");

    double all_time = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    double calculation_time = (double)(stop.tv_sec - middle.tv_sec + (middle.tv_usec - middle.tv_usec) / 1000000.0);
    printf("calculation took %lf s\n", calculation_time);
    printf("everything took %lf s\n", all_time);

    free(A);
    free(f);
}
