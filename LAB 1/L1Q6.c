/*
 * DAA Lab: Question 6 -- Element Uniqueness
 * For n random numbers, check if any duplicates exist.
 * Method: sort the numbers, then just check neighbouring elements --
 * if two equal numbers exist, they'll be next to each other after sorting.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    srand(time(NULL));

    int n, range;

    printf("Enter how many numbers to be generated: ");
    scanf("%d", &n);

    printf("Enter range of numbers: ");
    scanf("%d", &range);

    if (n <= 0 || range <= 0) {
        printf("n and range should be positive!\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }

    if (n <= 30) {
        printf("\nArray: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else {
        printf("\nGenerated %d numbers, first 10 -> ", n);
        for (int i = 0; i < 10; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    qsort(arr, n, sizeof(int), cmp);

    int found = 0;
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            if (!found) printf("Duplicates: ");
            found = 1;
            count++;

            if (count <= 20) {
                printf("%d ", arr[i]);
               }


            while (i < n - 1 && arr[i] == arr[i + 1]) i++;
        }
    }

    if (found) {
        printf("...");
        printf("\nduplicates were found \n", count);
    } else {
        printf("\nNo duplicates, all %d numbers are unique\n", n);
    }

    free(arr);
    return 0;
}
