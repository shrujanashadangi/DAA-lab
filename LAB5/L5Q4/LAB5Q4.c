// Q4: sort n randomly generated elements stored in a file using
// Heap Sort. Numbers go into input2.txt, sorted result into output2.txt.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    FILE *fin = fopen("input2.txt", "w");
    if (!fin) {
        printf("Error: could not create input2.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        fprintf(fin, "%d ", arr[i]);
    }
    fclose(fin);
    printf("Generated %d random numbers and stored in input2.txt\n", n);

    FILE *fr = fopen("input2.txt", "r");
    if (!fr) {
        printf("Error: could not open input2.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++)
        fscanf(fr, "%d", &arr[i]);
    fclose(fr);

    heapSort(arr, n);

    FILE *fout = fopen("output2.txt", "w");
    if (!fout) {
        printf("Error: could not create output2.txt\n");
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; i++)
        fprintf(fout, "%d ", arr[i]);
    fclose(fout);

    printf("Sorted numbers written to output2.txt\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
