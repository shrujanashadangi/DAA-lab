#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_two(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = malloc(sizeof(int) * n1);
    int* R = malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort_2way(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_2way(arr, l, m);
        merge_sort_2way(arr, m + 1, r);
        merge_two(arr, l, m, r);
    }
}

void merge_three(int arr[], int l, int mid1, int mid2, int r) {
    int n1 = mid1 - l + 1;
    int n2 = mid2 - mid1;
    int n3 = r - mid2;

    int* L = malloc(sizeof(int) * n1);
    int* M = malloc(sizeof(int) * n2);
    int* R = malloc(sizeof(int) * n3);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[mid2 + 1 + i];

    int i = 0, j = 0, k = 0, idx = l;

    // Merge elements from all 3 subarrays
    while (i < n1 && j < n2 && k < n3) {
        if (L[i] <= M[j] && L[i] <= R[k]) {
            arr[idx++] = L[i++];
        } else if (M[j] <= L[i] && M[j] <= R[k]) {
            arr[idx++] = M[j++];
        } else {
            arr[idx++] = R[k++];
        }
    }

    // Merge remaining elements between pairs of subarrays
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) arr[idx++] = L[i++];
        else arr[idx++] = M[j++];
    }
    while (j < n2 && k < n3) {
        if (M[j] <= R[k]) arr[idx++] = M[j++];
        else arr[idx++] = R[k++];
    }
    while (i < n1 && k < n3) {
        if (L[i] <= R[k]) arr[idx++] = L[i++];
        else arr[idx++] = R[k++];
    }

    // Copy any remaining elements
    while (i < n1) arr[idx++] = L[i++];
    while (j < n2) arr[idx++] = M[j++];
    while (k < n3) arr[idx++] = R[k++];

    free(L);
    free(M);
    free(R);
}

void merge_sort_3way(int arr[], int l, int r) {
    if (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = l + 2 * (r - l) / 3;

        merge_sort_3way(arr, l, mid1);
        merge_sort_3way(arr, mid1 + 1, mid2);
        merge_sort_3way(arr, mid2 + 1, r);

        merge_three(arr, l, mid1, mid2, r);
    }
}

void print_array(int arr[], int size) {
    if (size <= 12) {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("%d %d %d %d ... %d %d %d %d (Total: %d)\n",
               arr[0], arr[1], arr[2], arr[3],
               arr[size - 4], arr[size - 3], arr[size - 2], arr[size - 1], size);
    }
}

int main() {
    int n, choice;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    int* arr1 = malloc(sizeof(int) * n);
    int* arr2 = malloc(sizeof(int) * n);

    printf("\n1. Manual Input\n2. Auto Generate\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr1[i]);
            arr2[i] = arr1[i];
        }
    } else {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            int val = rand() % 10000;
            arr1[i] = val;
            arr2[i] = val;
        }
        printf("\nInput array: ");
        print_array(arr1, n);
    }

    // Time 2-way merge sort
    clock_t start = clock();
    merge_sort_2way(arr1, 0, n - 1);
    clock_t end = clock();
    double time_2way = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    // Time 3-way merge sort
    start = clock();
    merge_sort_3way(arr2, 0, n - 1);
    end = clock();
    double time_3way = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("\nSorted output:\n");
    printf("2-Way result: ");
    print_array(arr1, n);

    printf("3-Way result: ");
    print_array(arr2, n);

    printf("\nExecution time:\n");
    printf("2-Way merge sort : %.4f ms\n", time_2way);
    printf("3-Way merge sort : %.4f ms\n", time_3way);

    free(arr1);
    free(arr2);

    return 0;
}

