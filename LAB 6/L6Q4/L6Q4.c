/* DAA Lab 06 - Q4: Sorting a permutation using reverse(p, i, j) reverse(p, i, j) costs |j - i| + 1 (its length).
 * Sorts using a merge-sort structure where the merge step is done
 * via rotations (built from 3 reversals), aiming for O(n log^2 n) cost.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long totalCost = 0;
long long totalReversals = 0;

void reverse(int p[], int i, int j) {
    if (i > j) return;
    totalCost += (j - i + 1);
    totalReversals++;
    while (i < j) {
        int t = p[i];
        p[i] = p[j];
        p[j] = t;
        i++;
        j--;
    }
}

void rotate(int p[], int l, int mid, int r) {
    reverse(p, l, mid - 1);
    reverse(p, mid, r);
    reverse(p, l, r);
}

int lowerBoundPos(int p[], int lo, int hi, int key) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (p[mid] < key) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

/* first index in p[lo..hi) with value > key */
int upperBoundPos(int p[], int lo, int hi, int key) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (p[mid] <= key) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void mergeByRotation(int p[], int l, int mid, int r) {
    int leftLen = mid - l + 1;
    int rightLen = r - mid;
    if (leftLen <= 0 || rightLen <= 0) return; /* one side already empty */

    if (leftLen == 1) {
        int pos = lowerBoundPos(p, mid + 1, r + 1, p[l]);
        rotate(p, l, mid + 1, pos - 1);
        return;
    }

    if (rightLen == 1) {
        int pos = upperBoundPos(p, l, mid + 1, p[r]);
        rotate(p, pos, r, r);
        return;
    }

    int m1 = l + (leftLen - 1) / 2;
    int m2 = lowerBoundPos(p, mid + 1, r + 1, p[m1]);

    rotate(p, m1 + 1, mid + 1, m2 - 1);
    int newMid = m1 + (m2 - mid - 1);

    mergeByRotation(p, l, m1, newMid);
    mergeByRotation(p, newMid + 1, m2 - 1, r);
}

void sortByReversal(int p[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    sortByReversal(p, l, mid);
    sortByReversal(p, mid + 1, r);
    mergeByRotation(p, l, mid, r);
}

void printArr(int p[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter n (size of the permutation): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *p = malloc(n * sizeof(int));
    printf("Enter the permutation of 1..%d:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("\nOriginal permutation: ");
    printArr(p, n);

    sortByReversal(p, 0, n - 1);

    printf("Sorted permutation: ");
    printArr(p, n);

    printf("\nTotal reversals used: %lld\n", totalReversals);
    printf("Total cost (sum of reversal lengths): %lld\n", totalCost);

    double bound = n * log2((double)n) * log2((double)n);
    printf("O(n log^2 n) reference bound: %.1f\n", bound);

    free(p);
    return 0;
}
