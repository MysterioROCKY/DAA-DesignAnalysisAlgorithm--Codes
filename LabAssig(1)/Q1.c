#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    clock_t start, end;
    start = clock();
    int i, x, n;
    printf("How many elements?");
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; ++i)
    {
        a[i] = rand() % 1000;
    }

    printf("Enter element to search:");
    scanf("%d", &x);

    for (i = 0; i < n; ++i)
    {
        if (a[i] == x)
        {
            break;
        }
    }

    if (i < n)
    {
        printf("Element found at index %d \n", i);
    }
    else
    {
        printf("Element not found \n");
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f", duration);
}