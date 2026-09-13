/* DAA Lab 07 - Q4: Security switches
 * Reads the number of switches, all starting ON, and finds the minimum
 * sequence of toggles needed to turn them all OFF under the chain rule.
 */

#include <stdio.h>
#include <stdlib.h>

int *build_moves(int n, long long *len) {
    if (n == 1) {
        int *a = malloc(sizeof(int));
        a[0] = 1;
        *len = 1;
        return a;
    }
    long long prev_len;
    int *prev = build_moves(n - 1, &prev_len);

    long long new_len = 2 * prev_len + (n % 2 == 1 ? 1 : 0);
    int *out = malloc(new_len * sizeof(int));
    long long idx = 0;
    if (n % 2 == 1) out[idx++] = n;
    for (long long i = 0; i < prev_len; i++) {
        out[idx++] = prev[i];
        out[idx++] = n;
    }
    free(prev);
    *len = new_len;
    return out;
}

int verify(int n, int *moves, long long len) {
    int *sw = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sw[i] = 1;

    for (long long t = 0; t < len; t++) {
        int s = moves[t] - 1;
        int legal;
        if (s == n - 1) {
            legal = 1;
        } else {
            legal = sw[s + 1] == 1;
            for (int j = s + 2; j < n && legal; j++)
                if (sw[j] != 0) legal = 0;
        }
        if (!legal) { free(sw); return 0; }
        sw[s] ^= 1;
    }
    int all_off = 1;
    for (int i = 0; i < n; i++) if (sw[i] != 0) all_off = 0;
    free(sw);
    return all_off;
}

int main() {
    int n;
    printf("Enter number of switches: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    long long len;
    int *moves = build_moves(n, &len);

    printf("\nMinimum number of moves to turn off all %d switches: %lld\n", n, len);

    int print_all = len <= 200;
    if (!print_all) printf("(sequence has %lld moves, showing first 40 and last 10)\n", len);

    printf("\nMove sequence (switch numbers, 1 = leftmost, %d = rightmost):\n", n);
    if (print_all) {
        for (long long t = 0; t < len; t++) printf("%d ", moves[t]);
        printf("\n");
    } else {
        for (long long t = 0; t < 40; t++) printf("%d ", moves[t]);
        printf(" ... ");
        for (long long t = len - 10; t < len; t++) printf("%d ", moves[t]);
        printf("\n");
    }

    printf("\nReplaying the sequence against the actual switch rules: %s\n",
           verify(n, moves, len) ? "every move legal, ends all-OFF" : "INVALID sequence");

    free(moves);
    return 0;
}
