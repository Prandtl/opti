#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void main()
{
    // printf("Square root of %lf is %lf\n", 5.0, floor(sqrt(5.0)) );

    int number, i, j, maxiter, current;
    struct timeval start, stop;

    printf("Enter the number\n");
    scanf("%d", &number);

    printf("initialization...\n");
    int* primes = (int*) malloc((number + 1) * sizeof(int));

    #pragma loop count min(1024)
    for (i = 2; i <= number; i++)
    {
        primes[i] = i;
    }

    printf("done.\n");

    printf("sieving...\n");
    gettimeofday(&start, NULL);
    maxiter = floor(sqrt(number));
    #pragma parallel
    #pragma loop count min(512)
    for (i = 2; i <= maxiter; i++)
    {
        if (primes[i] != 0)
        {
            current = primes[i];
            for (j = current * 2; j <= number; j = j + current)
            {
                primes[j] = 0;
            }
        }
    }
    gettimeofday(&stop, NULL);
    printf("done.\n");
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("sieving took %lf s.\n", duration);
    int counter = 0;
    #pragma loop count min(512)
    for (i = 2; i <= number; i++)
    {
        if (primes[i] != 0)
        {
            counter++;
            // printf("%d\n", primes[i]);
        }
    }
    printf("amount of primes: "); printf("%d\n", counter);
    free(primes);
}