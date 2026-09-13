/* DAA Lab 07 - Q5: Hitting a moving target
 * Reads the number of hiding spots and prints a shooting sequence
 * guaranteed to hit a target that moves one spot every turn.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of hiding spots (n > 1): ");
    if (scanf("%d", &n) != 1 || n <= 1) return 1;

    printf("\nA guaranteed-hit strategy exists for every n >= 2.\n");

    int total_shots;
    int *seq;
    if (n == 2) {
        total_shots = 2;
        seq = malloc(2 * sizeof(int));
        seq[0] = 1;
        seq[1] = 1;
    } else {
        total_shots = 2 * (n - 2);
        seq = malloc(total_shots * sizeof(int));
        int shot = 0;
        for (int i = 2; i <= n - 1; i++) seq[shot++] = i;
        for (int i = n - 1; i >= 2; i--) seq[shot++] = i;
    }

    printf("Total shots needed (worst case): %d\n", total_shots);
    printf("\nShooting sequence:\n");
    for (int t = 0; t < total_shots; t++) printf("  shot %2d: spot %d\n", t + 1, seq[t]);

    int all_caught = 1;
    for (int start = 1; start <= n; start++) {
        for (int first_move_right = 0; first_move_right <= 1; first_move_right++) {
            int pos = start;
            int dir = first_move_right ? 1 : -1;
            int caught = 0;
            for (int t = 0; t < total_shots; t++) {
                if (t > 0) {
                    if (pos + dir < 1 || pos + dir > n) dir = -dir;
                    pos += dir;
                }
                if (seq[t] == pos) { caught = 1; break; }
            }
            if (!caught) all_caught = 0;
        }
    }
    printf("\nBrute-force check over every start position and direction: %s\n",
           all_caught ? "target is always caught" : "a case was missed");

    free(seq);
    return 0;
}
