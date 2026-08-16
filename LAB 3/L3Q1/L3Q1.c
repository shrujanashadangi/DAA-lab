//DAA lab 3 Q1:Binary vs Ternary search

#include <stdio.h>
#include <stdlib.h>

long cb, ct;

/* ---------- Binary Search ---------- */
int binarySearch(int a[], int n, int x) {
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;

        cb++;
        if (a[m] == x) {
            return m;
        }

        cb++;
        if (a[m] < x) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    return -1;
}

/* ---------- Ternary Search ---------- */
int ternarySearch(int a[], int n, int x) {
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;

        ct++;
        if (a[m1] == x) {
            return m1;
        }

        ct++;
        if (a[m2] == x) {
            return m2;
        }

        ct++;
        if (x < a[m1]) {
            hi = m1 - 1;
        } else {
            ct++;
            if (x > a[m2]) {
                lo = m2 + 1;
            } else {
                lo = m1 + 1;
                hi = m2 - 1;
            }
        }
    }
    return -1;
}

int isSorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void autoFill(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 2 * i;
    }
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *a = (int *)malloc(sizeof(int) * n);

    printf("How do you want to enter the array?\n");
    printf("1. Manual Input\n");
    printf("2. Auto-generate\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 2) {
        autoFill(a, n);
        printf("Auto-generated array: 0, 2, 4, ..., %d\n", a[n - 1]);
    } else {
        do {
            printf("Enter %d elements in SORTED (ascending) order:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            if (!isSorted(a, n)) {
                printf("Error: that is not in ascending order. Please enter it again.\n\n");
            }
        } while (!isSorted(a, n));
    }

    int x;
    printf("Enter the element x to search for: ");
    scanf("%d", &x);

    int pb = binarySearch(a, n, x);
    int pt = ternarySearch(a, n, x);

    printf("\nBinary Search\n");
    if (pb != -1)
        printf("Found %d at index %d\n", x, pb);
    else
        printf("%d not found\n", x);
    printf("Comparisons used: %ld\n", cb);

    printf("\nTernary Search\n");
    if (pt != -1)
        printf("Found %d at index %d\n", x, pt);
    else
        printf("%d not found\n", x);
    printf("Comparisons used: %ld\n", ct);

    if (cb < ct)
        printf("Binary search used FEWER comparisons (%ld < %ld) for this input.\n", cb, ct);
    else if (cb > ct)
        printf("Ternary search used fewer comparisons (%ld < %ld) for this input.\n", ct, cb);
    else
        printf("Both used the same number of comparisons (%ld) for this input.\n", cb);

    free(a);
    return 0;
}

