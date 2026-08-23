// Q2: given sets S1 and S2, check if some a in S1 and b in S2 add up to x.
// Idea: sort S2, then for each a in S1 binary search for (x - a). O(n log n).

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binSearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}

int readIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 0;
    return 1;
}

int main(void) {
    int n1, n2, x;

    printf("Enter size of S1: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("Invalid input: size must be a positive integer.\n");
        return 1;
    }
    int *s1 = malloc(n1 * sizeof(int));
    printf("Enter %d elements of S1: ", n1);
    if (!readIntArray(s1, n1)) {
        printf("Invalid input: expected %d integers.\n", n1);
        free(s1);
        return 1;
    }

    printf("Enter size of S2: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Invalid input: size must be a positive integer.\n");
        free(s1);
        return 1;
    }
    int *s2 = malloc(n2 * sizeof(int));
    printf("Enter %d elements of S2: ", n2);
    if (!readIntArray(s2, n2)) {
        printf("Invalid input: expected %d integers.\n", n2);
        free(s1); free(s2);
        return 1;
    }

    printf("Enter x: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input: x must be an integer.\n");
        free(s1); free(s2);
        return 1;
    }

    qsort(s2, n2, sizeof(int), cmp);

    int found = 0, a = 0, b = 0;
    for (int i = 0; i < n1 && !found; i++) {
        int need = x - s1[i];
        if (binSearch(s2, n2, need)) {
            found = 1;
            a = s1[i];
            b = need;
        }
    }

    if (found)
        printf("\nPair found: %d + %d = %d\n", a, b, x);
    else
        printf("\nNo pair adds up to %d\n", x);

    free(s1); free(s2);
    return 0;
}
