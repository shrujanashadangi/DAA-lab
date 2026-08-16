/* DAA Lab 03 - Q3: Min and Max using Divide and Conquer
 * Total comparisons: <= 3n/2 - 2 (bounded by 3n/2).
 */

#include <stdio.h>
#include <stdlib.h>

int cmp;

typedef struct {
    int min;
    int max;
} Pair;

Pair getMinMax(int a[], int l, int r) {
    Pair res, left, right;

    // only 1 element
    if (l == r) {
        res.min = a[l];
        res.max = a[l];
        return res;
    }

    // 2 elements
    if (r == l + 1) {
        cmp++;
        if (a[l] < a[r]) {
            res.min = a[l];
            res.max = a[r];
        } else {
            res.min = a[r];
            res.max = a[l];
        }
        return res;
    }

    // split in half
    int mid = l + (r - l) / 2;
    left = getMinMax(a, l, mid);
    right = getMinMax(a, mid + 1, r);

    // merge results
    cmp++;
    res.min = (left.min < right.min) ? left.min : right.min;

    cmp++;
    res.max = (left.max > right.max) ? left.max : right.max;

    return res;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = (int *)malloc(sizeof(int) * n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    cmp = 0;
    Pair ans = getMinMax(a, 0, n - 1);

    printf("\nMin: %d\n", ans.min);
    printf("Max: %d\n", ans.max);
    printf("Comparisons used: %d\n", cmp);
    printf("3n/2 bound: %.1f\n", 1.5 * n);

    free(a);
    return 0;
}
