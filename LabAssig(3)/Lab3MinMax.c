#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("How many elements? ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    int max = arr[0];
    int min = arr[0];
    int swaps = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            swaps++;
        }
        else if (arr[i] > max)
        {
            max = arr[i];
            swaps++;
        }
    }

    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);
    printf("Number of swaps are %d\n", swaps);
    return 0;
}