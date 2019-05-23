#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double func(double x)
{
    return sin(x)/(x * x) + 2 * sqrt(x) - 1;
}

void main()
{
    int size, i;
    struct timeval start, stop;

    time_t t;

    srand((unsigned)time(&t));

    printf("Enter the number\n");
    scanf("%d", &size);
    int *a = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = sin(i) * 10;
    }
    printf("calculation\n");
    gettimeofday(&start, NULL);
    #pragma omp parallel for
    for (i = 0; i < size; i++)
    {
        a[i] = func(a[i]);
    }
    gettimeofday(&stop, NULL);
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("calculation took %lf s.\n", duration);

    double sum = 0;
    for(int i=0;i<size;i++)
    {
        sum += a[i];
    }
    printf("sum= %lf\n", sum);
}