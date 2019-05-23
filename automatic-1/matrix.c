#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define X 1000
#define Y 1000
#define Z 1000

float *A, *B, *C;

void generate_matrices()
{
    int i, j;
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            A[Y * i + j] = (float)((i + j) % 10);
        }
    }
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < Z; j++)
        {
            B[Z * i + j] = (float)((i + j) % 10);
        }
    }
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

void multiply_matrices(float A[], float B[], float C[], int x, int y, int z)
{
    int i, j, k;
    float sum;
    #pragma noparallel
    for (i = 0; i < x; i++)
    {
        // float* buffer = (float*) malloc(z * sizeof(float));
        for (j = 0; j < z; j++)
        {
            sum = 0;
            for (k = 0; k < y; k++)
            {
                sum = sum + A[i * y + k] * B[k * z + j];
            }
            C[z * i + j] = sum;
        }
        // memcpy(&C[z * i], buffer, z * sizeof(float));
        // free(buffer);
    }
}

void main()
{
    A = (float *)malloc(X * Y * sizeof(float));
    printf("A.\n");
    B = (float *)malloc(Y * Z * sizeof(float));
    printf("\tB.\n");
    C = (float *)malloc(X * Z * sizeof(float));
    printf("\t\tC.\n");

    struct timeval start, stop;

    double seconds;
    generate_matrices();

    printf("starting multiplication\n");
    gettimeofday(&start, NULL);
    multiply_matrices(A, B, C, X, Y, Z);
    gettimeofday(&stop, NULL);
    printf("finished.\n");

    if (C[0] < 0)
    {
        printf("negative\n");
    }
    else
    {
        printf("positive\n");
    }
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("multiplication took %lf s.\n", duration);

    double sum = 0;
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Z; j++)
        {
            sum += C[i * X + j];
        }
    }

    printf("sum: %lf\n", sum);
    free(A);
    free(B);
    free(C);
}
