#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double func(double x)
{
    return x * x + 2 * sqrt(x) - 1;
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
        a[i] = rand() % 1000;
    }

    gettimeofday(&start, NULL);
    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < size; i++)
        {
            a[i] = func(a[i]);
        }
    }
    gettimeofday(&stop, NULL);
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("calculation took %lf s.\n", duration);

    if (a[0] > 1000)
    {
        printf("first one is more than 1k\n");
    }
    else
    {
        printf("first one is smaller than 1k\n");
    }
}