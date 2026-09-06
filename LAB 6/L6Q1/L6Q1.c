/* DAA Lab 06 - Q1: 1D array operations and their complexities
 * Reads n unsorted integers and runs max, top-2, mean, median, std dev, mode, duplicate removal, reverse, and a random-pivot partition
 * (elements >= pivot first, elements < pivot after) on them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int findMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

typedef struct {
    int first;
    int second;
} TopTwo;

TopTwo firstSecondLargest(int a[], int n) {
    TopTwo result;
    if (a[0] > a[1]) {
        result.first = a[0];
        result.second = a[1];
    } else {
        result.first = a[1];
        result.second = a[0];
    }

    for (int i = 2; i < n; i++) {
        if (a[i] > result.first) {
            result.second = result.first;
            result.first = a[i];
        } else if (a[i] > result.second) {
            result.second = a[i];
        }
    }
    return result;
}

double findMean(int a[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (double)sum / n;
}

int cmpInt(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}

double findMedian(int a[], int n) {
    int *b = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    qsort(b, n, sizeof(int), cmpInt);

    double med;
    if (n % 2 == 0)
        med = (b[n / 2 - 1] + b[n / 2]) / 2.0;
    else
        med = b[n / 2];

    free(b);
    return med;
}

double findStdDev(int a[], int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (a[i] - mean) * (a[i] - mean);
    return sqrt(sum / n);
}

int findMode(int a[], int n) {
    int *b = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    qsort(b, n, sizeof(int), cmpInt);

    int mode = b[0], bestCount = 1, curCount = 1;
    for (int i = 1; i < n; i++) {
        curCount = (b[i] == b[i - 1]) ? curCount + 1 : 1;
        if (curCount > bestCount) {
            bestCount = curCount;
            mode = b[i];
        }
    }

    free(b);
    return mode;
}

void removeDuplicates(int a[], int n) {
    int *b = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    qsort(b, n, sizeof(int), cmpInt);

    int k = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] != b[k - 1]) {
            b[k] = b[i];
            k++;
        }
    }

    printf("Array after removing duplicates: ");
    printArr(b, k);
    free(b);
}

void reverseArray(int a[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

/* elements >= pivot end up before elements < pivot */
int partitionArray(int a[], int n) {
    int pivotIndex = rand() % n;
    int pivot = a[pivotIndex];

    int t = a[pivotIndex];
    a[pivotIndex] = a[n - 1];
    a[n - 1] = t;

    int store = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= pivot) {
            t = a[i];
            a[i] = a[store];
            a[store] = t;
            store++;
        }
    }
    t = a[store];
    a[store] = a[n - 1];
    a[n - 1] = t;
    return store;
}

int main(void) {
    srand(time(NULL));
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = malloc(sizeof(int) * n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("\nOriginal array: ");
    printArr(a, n);

    printf("\nMax element: %d\n", findMax(a, n));

    if (n >= 2) {
        TopTwo top = firstSecondLargest(a, n);
        printf("First largest: %d, Second largest: %d\n", top.first, top.second);
    }

    double mean = findMean(a, n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", findMedian(a, n));
    printf("Standard Deviation: %.2f\n", findStdDev(a, n, mean));
    printf("Mode: %d\n", findMode(a, n));

    removeDuplicates(a, n);

    reverseArray(a, n);
    printf("Reversed array: ");
    printArr(a, n);

    int pivotPos = partitionArray(a, n);
    printf("Array after partition (>= pivot first, < pivot after): ");
    printArr(a, n);
    printf("Pivot ended up at index %d, value %d\n", pivotPos, a[pivotPos]);

    free(a);
    return 0;
}
