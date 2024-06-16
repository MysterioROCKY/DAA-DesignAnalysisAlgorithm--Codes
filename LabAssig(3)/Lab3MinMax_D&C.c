#include <stdio.h>
#include <stdlib.h>
int max, min, swaps;
int a[1000];
void maxmin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
                swaps++;
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1)
            {
                max = max1;
            }
            if (min > min1)
            {
                min = min1;
            }
        }
    }
}
int main()
{
    int i, num;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        a[i] = rand() % 1000;
    }

    max = a[0];
    min = a[0];
    maxmin(1, num);
    printf("Minimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    printf("Number of swaps are %d\n", swaps);
    return 0;
}