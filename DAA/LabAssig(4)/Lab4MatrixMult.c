#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    for (int s = 2; s <= 512; s = s * 2)
    {
        int n = s;

        int matrix1[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix1[i][j] = rand() % 99 + 1;
            }
        }

        int matrix2[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix2[i][j] = rand() % 99 + 1;
            }
        }

        int result[n][n];
        clock_t start_time = clock();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        clock_t end_time = clock();
        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        printf("Size: %d\tTime: %f\n", n, elapsed_time);

        /*  To print the result of matrix multiplication
        printf("Result:->\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    return 0;
}