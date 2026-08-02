// DAA Lab - Bubble sort performance
// version 1: stops early if array already sorted
// version 2: always runs all n-1 passes
// enter n and it'll generate a random array and compare both

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble1(int arr[], int n) {
    int cnt = 0;
    int swapped = 1;
    int pass = 0;

    while (swapped && pass < n - 1) {
        swapped = 0;
        for (int j = 0; j < n - pass - 1; j++) {
            cnt++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        pass++;
    }
    return cnt;
}

int bubble2(int arr[], int n) {
    int cnt = 0;

    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - pass - 1; j++) {
            cnt++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return cnt;
}

void copyArr(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter n (array size): ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("n should be more than 1.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    if (n <= 30) {
        printf("\nArray: ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    } else {
        printf("\nGenerated %d random numbers (too many to print)\n", n);
    }

    copyArr(arr, temp, n);
    int c1 = bubble1(temp, n);

    copyArr(arr, temp, n);
    int c2 = bubble2(temp, n);

    printf("\nComparisons (stops early version) = %d\n", c1);
    printf("Comparisons (always full version)  = %d\n", c2);

    free(arr);
    free(temp);
    return 0;
}
