// Q4: find the time when the most people are present at a party.
// Idea: turn each entry into a +1 event and each exit into a -1 event,
// sort all events by time, sweep and track the running total. O(n log n).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int delta;
} Event;

int cmp(const void *a, const void *b) {
    return ((Event *)a)->time - ((Event *)b)->time;
}

int main(void) {
    int n;
    printf("Enter number of persons: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    Event *ev = malloc(2 * n * sizeof(Event));
    printf("Enter %d pairs as: entry_time exit_time (exit must be greater than entry)\n", n);
    for (int i = 0; i < n; i++) {
        int a, b;
        if (scanf("%d %d", &a, &b) != 2 || b <= a) {
            printf("Invalid input: exit time must be greater than entry time.\n");
            free(ev);
            return 1;
        }
        ev[2 * i] = (Event){a, 1};
        ev[2 * i + 1] = (Event){b, -1};
    }

    qsort(ev, 2 * n, sizeof(Event), cmp);

    int count = 0, best = 0, bestTime = ev[0].time;
    for (int i = 0; i < 2 * n; i++) {
        count += ev[i].delta;
        if (count > best) {
            best = count;
            bestTime = ev[i].time;
        }
    }

    printf("\nMax %d people present, starting at time %d\n", best, bestTime);

    free(ev);
    return 0;
}
