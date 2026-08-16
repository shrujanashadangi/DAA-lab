//DAA Lab 03 - Q6: Loop invariant in Selection Sort

#include <stdio.h>
#include <stdlib.h>

void selSort(int a[], int n, long *cmp) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            (*cmp)++;
            if (a[j] < a[m]) m = j;
        }
        if (m != i) {
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
        }
    }
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = (int *)malloc(sizeof(int) * n);
    if (!a) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nBefore: ");
    printArr(a, n);

    long cmp = 0;
    selSort(a, n, &cmp);

    printf("After:  ");
    printArr(a, n);

    printf("\nComparisons = %ld\n", cmp);
    printf("n*(n-1)/2   = %ld\n", (long)n * (n - 1) / 2);

    free(a);
    return 0;
}
