// Q3: sort n randomly generated elements stored in a file using
// Quicksort. Numbers go into input.txt, sorted result into output.txt.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(void) {
    int n;
    printf("Enter number of random elements to generate: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    srand(time(NULL));
    FILE *fin = fopen("input.txt", "w");
    if (!fin) {
        printf("Error: could not create input.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        fprintf(fin, "%d ", arr[i]);
    }
    fclose(fin);
    printf("Generated %d random numbers and stored in input.txt\n", n);

    FILE *fr = fopen("input.txt", "r");
    if (!fr) {
        printf("Error: could not open input.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++)
        fscanf(fr, "%d", &arr[i]);
    fclose(fr);

    quickSort(arr, 0, n - 1);

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error: could not create output.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);

    printf("Sorted numbers written to output.txt\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
