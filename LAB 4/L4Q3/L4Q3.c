// Q3: check if k elements of S add up to T. O(n^(k-1) log n).
// Idea: sort S, fix the first (k-2) numbers with nested/recursive loops,
// then solve the last 2 with a linear scan + binary search (O(n log n)).

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binSearch(int arr[], int lo, int hi, int target) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int twoSum(int arr[], int n, int start, int rem, int *out, int idx) {
    for (int i = start; i < n; i++) {
        int j = binSearch(arr, i + 1, n - 1, rem - arr[i]);
        if (j != -1) {
            out[idx] = arr[i];
            out[idx + 1] = arr[j];
            return 1;
        }
    }
    return 0;
}

int findK(int arr[], int n, int start, int k, int rem, int *out, int idx) {
    if (k == 2)
        return twoSum(arr, n, start, rem, out, idx);

    for (int i = start; i <= n - k; i++) {
        out[idx] = arr[i];
        if (findK(arr, n, i + 1, k - 1, rem - arr[i], out, idx + 1))
            return 1;
    }
    return 0;
}

int main(void) {
    int n, k, T;

    printf("Enter size of S: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    int *s = malloc(n * sizeof(int));
    printf("Enter %d elements of S: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &s[i]) != 1) {
            printf("Invalid input: expected %d integers.\n", n);
            free(s);
            return 1;
        }
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k < 2 || k > n) {
        printf("Invalid input: k must be an integer between 2 and n.\n");
        free(s);
        return 1;
    }

    printf("Enter target T: ");
    if (scanf("%d", &T) != 1) {
        printf("Invalid input: T must be an integer.\n");
        free(s);
        return 1;
    }

    qsort(s, n, sizeof(int), cmp);

    int *out = malloc(k * sizeof(int));
    if (findK(s, n, 0, k, T, out, 0)) {
        printf("\nFound %d numbers that add up to %d: ", k, T);
        for (int i = 0; i < k; i++) printf("%d ", out[i]);
        printf("\n");
    } else {
        printf("\nNo %d numbers add up to %d\n", k, T);
    }

    free(s); free(out);
    return 0;
}
