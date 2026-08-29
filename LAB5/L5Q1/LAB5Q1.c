// Q1: find the median of n numbers without sorting the list.
// use Quickselect to directly fetch the middle-ranked elements instead of sorting everything first. O(n) average time.

#include <stdio.h>
#include <stdlib.h>

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

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) return arr[low];
    int p = partition(arr, low, high);
    if (p == k) return arr[p];
    else if (k < p) return quickSelect(arr, low, p - 1, k);
    else return quickSelect(arr, p + 1, high, k);
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input: expected integers.\n");
            free(arr);
            return 1;
        }
    }

    double median;
    if (n % 2 == 1) {
        int *copy = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) copy[i] = arr[i];
        median = quickSelect(copy, 0, n - 1, n / 2);
        free(copy);
    } else {
        int *copy1 = malloc(n * sizeof(int));
        int *copy2 = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) { copy1[i] = arr[i]; copy2[i] = arr[i]; }
        int left = quickSelect(copy1, 0, n - 1, n / 2 - 1);
        int right = quickSelect(copy2, 0, n - 1, n / 2);
        median = (left + right) / 2.0;
        free(copy1); free(copy2);
    }

    printf("\nMedian = %.2f\n", median);

    free(arr);
    return 0;
}
