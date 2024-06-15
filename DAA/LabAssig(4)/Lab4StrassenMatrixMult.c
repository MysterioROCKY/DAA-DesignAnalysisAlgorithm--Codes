#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2 // Change the maximum matrix size as needed

void printMatrix(int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

void strassenMultiply(int A[N][N], int B[N][N], int C[N][N], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int size = n / 2;
    int A11[size][size], A12[size][size], A21[size][size], A22[size][size];
    int B11[size][size], B12[size][size], B21[size][size], B22[size][size];
    int C11[size][size], C12[size][size], C21[size][size], C22[size][size];
    int P1[size][size], P2[size][size], P3[size][size], P4[size][size];
    int P5[size][size], P6[size][size], P7[size][size];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size];
            A21[i][j] = A[i + size][j];
            A22[i][j] = A[i + size][j + size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size];
            B21[i][j] = B[i + size][j];
            B22[i][j] = B[i + size][j + size];
        }
    }

    // Calculate the seven products
    strassenMultiply(A11, B11, P1, size);
    strassenMultiply(A12, B21, P2, size);
    strassenMultiply(A11, B12, P3, size);
    strassenMultiply(A12, B22, P4, size);
    strassenMultiply(A21, B11, P5, size);
    strassenMultiply(A22, B12, P6, size);
    strassenMultiply(A21, B21, P7, size);

    // Calculate the resulting submatrices
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C11[i][j] = P1[i][j] + P2[i][j] - P3[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P4[i][j] + P6[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P4[i][j] - P5[i][j];
        }
    }

    // Combine the resulting submatrices to get the final result
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

int main()
{
    for(int s = 1; s < 10; s = s++){
    int n;
    scanf("%d", &n);

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

    // Strassen multiplication code
    strassenMultiply(matrix1, matrix2, result, n);

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Size: %d\tTime: %f\n", n, elapsed_time);

    // Uncomment the following lines to print the result (for testing)
    /*
    printf("Result:\n");
    printMatrix(result);
    printf("\n");
    */
}
    return 0;
}
