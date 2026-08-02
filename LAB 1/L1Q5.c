/*
 * DAA Lab: Find the Partition Point
 * Array A contains a run of 0s followed by a run of 1s, e.g. 0 0 0 1 1 1
 * Goal: find the index where the switch from 0 to 1 happens.
 *
 * Method: binary search -- keep checking the middle element and
 * throwing away the half of the array that can't contain the answer.
 */

#include <stdio.h>
#include <stdlib.h>

int findPartitionPoint(int arr[], int n) {
    int low = 0, high = n - 1;
    int result = n;   // if we never find a 1, this stays as n

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

/* Checks that the array is genuinely "0's followed by 1's" with no
   mixing -- i.e. once we see a 1, every element after it must also be 1. */
int isValidPattern(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 1 && arr[i + 1] == 0) {
            return 0;   // found a 1 immediately followed later by a 0 -- invalid
        }
    }
    return 1;
}

/* Keeps asking until the user types exactly 0 or 1. Rejects anything else. */
int readBinaryValue(int position) {
    int val;
    while (1) {
        printf("  Element %d: ", position);
        if (scanf("%d", &val) != 1) {
            printf("  That's not a valid number. Please enter 0 or 1.\n");
            while (getchar() != '\n');   // clear the bad input
            continue;
        }
        if (val == 0 || val == 1) {
            return val;
        }
        printf("  Invalid! Only 0 or 1 is allowed. Try again.\n");
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be a positive number.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    printf("Enter %d elements (only 0's and 1's, 0's must come before 1's):\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = readBinaryValue(i + 1);
    }

    printf("\nArray you entered: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    if (!isValidPattern(arr, n)) {
        printf("\nThis array is NOT in the required format.\n");
        printf("It must be all 0's followed by all 1's\n");
        free(arr);
        return 1;
    }

    int point = findPartitionPoint(arr, n);

    if (point == n) {
        printf("\nNo 1 was found -- the entire array is 0's.\n");
        printf("There is no partition point in this case.\n");
    } else if (point == 0) {
        printf("\nNo 0 was found -- the entire array is 1's.\n");
        printf("The partition point is at index 0 (the very first element).\n");
    } else {
        printf("\nPartition point is at index %d\n", point);
        printf("(Everything before index %d is 0, everything from index %d onward is 1)\n", point, point);
    }

    free(arr);
    return 0;
}
