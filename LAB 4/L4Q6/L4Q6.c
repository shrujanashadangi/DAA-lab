// Q6: find a point covered by the most intervals.
// Idea: turn each left end into a start event and each right end into an
// end event, sort (start before end on ties, since intervals are closed),
// sweep and track the running count. O(n log n).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int point;
    int type; // 0 = start, 1 = end
} Event;

int cmp(const void *a, const void *b) {
    Event *e1 = (Event *)a, *e2 = (Event *)b;
    if (e1->point != e2->point) return e1->point - e2->point;
    return e1->type - e2->type;
}

int main(void) {
    int n;
    printf("Enter number of intervals: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    Event *ev = malloc(2 * n * sizeof(Event));
    printf("Enter %d intervals as: left right (right must be equal to or greater than left)\n", n);
    for (int i = 0; i < n; i++) {
        int l, r;
        if (scanf("%d %d", &l, &r) != 2 || r < l) {
            printf("Invalid input: each interval needs right greater than or equal to left.\n");
            free(ev);
            return 1;
        }
        ev[2 * i] = (Event){l, 0};
        ev[2 * i + 1] = (Event){r, 1};
    }

    qsort(ev, 2 * n, sizeof(Event), cmp);

    int count = 0, best = 0, bestPoint = ev[0].point;
    for (int i = 0; i < 2 * n; i++) {
        if (ev[i].type == 0) {
            count++;
            if (count > best) {
                best = count;
                bestPoint = ev[i].point;
            }
        } else {
            count--;
        }
    }

    printf("\nPoint %d is covered by %d intervals (max)\n", bestPoint, best);

    free(ev);
    return 0;
}
