#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s[2000];
int f[2000];

void quickSort(int s[], int f[], int low, int high) {
    if (low < high) {
        int pivot = f[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (f[j] < pivot) {
                i++;
                // Swap s[i] and s[j]
                int temp_s = s[i];
                s[i] = s[j];
                s[j] = temp_s;
                // Swap f[i] and f[j]
                int temp_f = f[i];
                f[i] = f[j];
                f[j] = temp_f;
            }
        }

        // Swap s[i+1] and s[high]
        int temp_s = s[i + 1];
        s[i + 1] = s[high];
        s[high] = temp_s;
        // Swap f[i+1] and f[high]
        int temp_f = f[i + 1];
        f[i + 1] = f[high];
        f[high] = temp_f;

        int pi = i + 1;

        quickSort(s, f, low, pi - 1);
        quickSort(s, f, pi + 1, high);
    }
}

void actSelect(int s[], int f[], int n) {
    int i, j;
    printf("Following activities are selected\n");

    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    clock_t start, end;
    start = clock();

    int i, num;
    srand(time(NULL));
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        s[i] = rand() % 110;
    }
    for (i = 0; i < num; i++) {
        f[i] = (s[i] + rand() % 110);
    }
    int n = num;

    for (i = 0; i < num; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    for (int j = 0; j < num; j++) {
        printf("%d ", f[j]);
    }
    printf("\n");

    // Sort activities based on finish times and rearrange s[] accordingly
    quickSort(s, f, 0, n - 1);

    printf("Activities after sorting:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    for (int j = 0; j < num; j++) {
        printf("%d ", f[j]);
    }
    printf("\n");

    actSelect(s, f, n);
    printf("\n");

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Time taken to execute in seconds : %f", duration);

    return 0;
}
