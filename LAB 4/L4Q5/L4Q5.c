// Q5: merge overlapping intervals.
// Idea: sort by start, then sweep and extend/merge as we go. O(n log n).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval *)a)->x - ((Interval *)b)->x;
}

int main(void) {
    int n;
    printf("Enter number of intervals: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    Interval *iv = malloc(n * sizeof(Interval));
    printf("Enter %d intervals as: x y (y must be greater than x)\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &iv[i].x, &iv[i].y) != 2 || iv[i].y <= iv[i].x) {
            printf("Invalid input: each interval needs y greater than x.\n");
            free(iv);
            return 1;
        }
    }

    qsort(iv, n, sizeof(Interval), cmp);

    Interval *merged = malloc(n * sizeof(Interval));
    int count = 0;
    Interval cur = iv[0];

    for (int i = 1; i < n; i++) {
        if (iv[i].x <= cur.y) {
            if (iv[i].y > cur.y) cur.y = iv[i].y;
        } else {
            merged[count++] = cur;
            cur = iv[i];
        }
    }
    merged[count++] = cur;

    printf("\nMerged intervals: ");
    for (int i = 0; i < count; i++)
        printf("(%d,%d) ", merged[i].x, merged[i].y);
    printf("\n");

    free(iv); free(merged);
    return 0;
}
