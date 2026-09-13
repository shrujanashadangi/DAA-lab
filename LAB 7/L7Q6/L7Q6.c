/* DAA Lab 07 - Q6: The best time to be alive
 * Reads each scientist's birth and death year and finds the year when
 * the largest number of them were alive at the same time.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct { int year; int delta; int order; } event;

int cmp(const void *a, const void *b) {
    const event *ea = a, *eb = b;
    if (ea->year != eb->year) return ea->year - eb->year;
    return ea->order - eb->order;
}

int main() {
    int n;
    printf("Enter number of scientists: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    event *ev = malloc(2 * n * sizeof(event));
    int *birth = malloc(n * sizeof(int));
    int *death = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Scientist %d - birth year: ", i + 1);
        scanf("%d", &birth[i]);
        printf("Scientist %d - death year: ", i + 1);
        scanf("%d", &death[i]);
        ev[2 * i] = (event){ birth[i], 1, 1 };
        ev[2 * i + 1] = (event){ death[i], -1, 0 };
    }

    qsort(ev, 2 * n, sizeof(event), cmp);

    int best = 0, best_year = 0, alive = 0;
    for (int i = 0; i < 2 * n; i++) {
        alive += ev[i].delta;
        if (alive > best) { best = alive; best_year = ev[i].year; }
    }

    printf("\nLargest number of scientists alive at the same time: %d\n", best);
    printf("First year that peak is reached: %d\n", best_year);

    int brute_best = 0, brute_year = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (birth[j] <= birth[i] && death[j] > birth[i]) count++;
        if (count > brute_best) { brute_best = count; brute_year = birth[i]; }
    }
    printf("\nBrute-force cross-check: %d alive, first at year %d\n", brute_best, brute_year);
    printf("Match: %s\n", brute_best == best ? "yes" : "no");

    free(ev);
    free(birth);
    free(death);
    return 0;
}
