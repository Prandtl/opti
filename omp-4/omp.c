#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void main()
{
    int number, blocksize, initialPrimesCounter, current, counter;
    struct timeval start, stop;

    printf("Enter the number\n");
    scanf("%d", &number);

    printf("initialization...\n");
    blocksize = floor(sqrt(number));
    int *inititalSieve = (int *)malloc((blocksize) * sizeof(int));
    int *inititalPrimes = (int *)malloc((blocksize) * sizeof(int));

    for (int i = 0; i < blocksize; i++)
    {
        inititalSieve[i] = i + 2;
    }

    printf("done.\n");

    printf("sieving...\n");
    gettimeofday(&start, NULL);
    initialPrimesCounter = 0;
    for (int i = 0; i <= blocksize - 2; i++)
    {
        if (inititalSieve[i] != 0)
        {
            current = i + 2;
            inititalPrimes[initialPrimesCounter] = current;
            initialPrimesCounter++;
            for (int j = current * 2; j <= blocksize; j = j + current)
            {
                inititalSieve[j - 2] = 0;
            }
        }
    }


    int *blockSieve = (int *)malloc((number) * sizeof(int));
    memset(blockSieve, 0, number);

    counter = 0;

    #pragma omp parallel for reduction(+:counter)
    for (int k = 1, maxk = number / blocksize; k < maxk; k++)
    {
        int start = k * blocksize + 1;
        // printf("%d\n", start);
        for (int i = 0; i < initialPrimesCounter; i++)
        {
            int startIndex = (start + inititalPrimes[i] - 1) / inititalPrimes[i];
            // printf("%d: %d, %d\n", inititalPrimes[i], start + inititalPrimes[i] - 1, startIndex);
            int s = startIndex * inititalPrimes[i];
            for (; s < start + blocksize; s += inititalPrimes[i])
            {
                // printf("%d: %d\n", inititalPrimes[i], s);
                blockSieve[s] = 1;
            }
        }
        
        for (int j = start; j < start + blocksize; j++)
        {
            // printf("%d: %d\n",j , blockSieve[j]);
            if (blockSieve[j] == 0)
            {
                counter++;

                // inititalPrimes[initialPrimesCounter] = j;
                // initialPrimesCounter++;
            }
        }
    }
    // printf("%d\n", initialPrimesCounter);
    // for(int i = 0; i< initialPrimesCounter;i++){
    //     printf("%d\n", inititalPrimes[i]);

    // }

    gettimeofday(&stop, NULL);
    printf("done.\n");
    double duration = (double)(stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / 1000000.0);
    printf("sieving took %lf s.\n", duration);
    printf("amount of primes: ");
    printf("%d\n", counter + initialPrimesCounter);
    free(inititalSieve);
}