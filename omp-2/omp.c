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
    int size, teamsize, i;
    struct timeval start, stop;

    time_t t;

    srand((unsigned)time(&t));

    printf("Enter the number\n");
    scanf("%d", &size);

    printf("Enter team size\n");
    scanf("%d", &teamsize);

    int *a = (int *)malloc(size * sizeof(int));
    int *b = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = 0;
        b[i] = rand() % size;
    }

    gettimeofday(&start, NULL);

    #pragma omp parallel for reduction(+:a[:size]) num_threads(teamsize)
    for (int n = 0; n < size; n++)
    {
        a[b[n]]++;
    }

    gettimeofday(&stop, NULL);
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("calculation took %lf s.\n", duration);

    int sum = 0;
    for(int n = 0; n < size; n++)
    {
        sum += a[n];
    }
    if (sum == size)
    {
        printf("everything is ok\n");
    }
    else
    {
        printf("my spider sense is tingling\n");
    }

    // for (i = 0; i < size; i++)
    // {
    //     printf("%d\n", b[i]);
    // }
    // printf("\n");
    // for (i = 0; i < size; i++)
    // {
    //     printf("%d\n", a[i]);
    // }
}