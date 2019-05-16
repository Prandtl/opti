#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void main()
{
    int number, i, j;
    struct timeval start, stop;

    printf("Enter the number\n");
    scanf("%d", &number);

    printf("initialization...\n");
    int* primes = (int*) malloc((number + 1) * sizeof(int));;

    for (i = 2; i <= number; i++)
    {
        primes[i] = i;
    }

    printf("done.\n");

    printf("sieving...\n");
    gettimeofday(&start, NULL);
    for (i = 2; (i * i) <= number; i++)
    {
        if (primes[i] != 0)
        {
            for (j = 2; j < number; j++)
            {
                if (primes[i] * j > number)
                {
                    break;
                }
                else
                {
                    primes[primes[i] * j] = 0;
                }
            }
        }
    }
    gettimeofday(&stop, NULL);
    printf("done.\n");
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("sieving took %lf s.\n", duration);
    printf("amount of primes: ");
    int counter = 0;
    for (i = 2; i <= number; i++)
    {
        if (primes[i] != 0)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    free(primes);
}