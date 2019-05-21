#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double func(double x)
{
    return log(x + 1);
}

void main()
{
    int size, i, sum;
    struct timeval start, stop;

    printf("Enter the number\n");
    scanf("%d", &size);

    gettimeofday(&start, NULL);
    sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < size; i++)
    {
        sum += func(i);
    }
    gettimeofday(&stop, NULL);
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("calculation took %lf s.\n", duration);

    printf("sum: %d\n", sum);
}