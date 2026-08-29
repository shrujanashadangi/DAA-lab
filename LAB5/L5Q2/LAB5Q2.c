// Q2: find the k'th smallest element of n numbers without sorting the list
// Quickselect - partition like quicksort but recurse into only the half that can contain the k'th rank. O(n) average time.

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

// k is 1-based: k = 1 means the smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) return arr[low];
    int p = partition(arr, low, high);
    int pos = p - low + 1;
    if (pos == k) return arr[p];
    else if (k < pos) return quickSelect(arr, low, p - 1, k);
    else return quickSelect(arr, p + 1, high, k - pos);
}

int main(void) {
    int n, k;
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

    printf("Enter K (1 = smallest): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > n) {
        printf("Invalid input: K must be between 1 and %d.\n", n);
        free(arr);
        return 1;
    }

    int result = quickSelect(arr, 0, n - 1, k);
    printf("\n%dth smallest element = %d\n", k, result);

    free(arr);
    return 0;
}
