#include <stdio.h>
#include <stdlib.h>

#define X 2000
#define Y 2000
#define Z 2000

float *A, *B, *C;

void generate_matrices() {
    int i, j;
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            A[Y * i + j] = (float)rand()/RAND_MAX*20.0 - 10.0;
        }
    }
    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < Z; j++)
        {
            B[Z * i + j] = (float)rand()/RAND_MAX*20.0 - 10.0;
        }
    }
}

void print_matrice(float M[], int r, int c) {
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

void multiply_matrices(float A[], float B[], float C[], int x, int y, int z) {
    int i, j, k;
    float sum;
    #pragma parallel
    for (i = 0; i < x; i++)
    {
        #pragma parallel
        for (j = 0; j < z; j++)
        {
            sum = 0;
            for (k = 0; k < y; k++)
            {
                sum = sum + A[i * y + k] * B[k * z + j];
            }
            C[z * i + j] = sum;
        }
    }
}

void main() 
{
    A = (float*) malloc(X * Y * sizeof(float));printf("A.\n");
    B = (float*) malloc(Y * Z * sizeof(float));printf("\tB.\n");
    C = (float*) malloc(X * Z * sizeof(float));printf("\t\tC.\n");

    clock_t c0, c1, c2;
    double seconds;
    c0 = clock();
    generate_matrices();
    printf("starting multiplication\n"); c1 = clock();

    multiply_matrices(A, B, C, X, Y, Z);
    if (C[0] < 0)
    {
        printf("negative\n");
    }
    else {
        printf("positive\n");
    }

    c2 = clock(); printf("finished.\n");

    int cpu_time_used = (c2 - c1);
    int cpu_time_used_all = (c2 - c0);
    printf("multiplication took %i ticks\n", cpu_time_used);
    printf("everything took %i ticks\n", cpu_time_used_all);

    free(A);
    free(B);
    free(C);
}
