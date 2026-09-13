/* DAA Lab 07 - Q3: Reve's puzzle (4-peg Tower of Hanoi)
 * Reads the number of disks and finds the minimum number of moves
 * using the Frame-Stewart method, then prints the full move sequence.
 */

#include <stdio.h>
#include <stdlib.h>

long long t3(int n) { return (1LL << n) - 1; }

long long *t4;
int *split_k;
int move_count = 0;

void build_frame_stewart(int n) {
    t4 = malloc((n + 1) * sizeof(long long));
    split_k = malloc((n + 1) * sizeof(int));
    t4[0] = 0;
    if (n >= 1) { t4[1] = 1; split_k[1] = 1; }
    for (int m = 2; m <= n; m++) {
        long long best = -1;
        int best_k = 1;
        for (int k = 1; k <= m - 1; k++) {
            long long cost = 2 * t4[k] + t3(m - k);
            if (best == -1 || cost < best) { best = cost; best_k = k; }
        }
        t4[m] = best;
        split_k[m] = best_k;
    }
}

void hanoi3(int n, char from, char via, char to) {
    if (n == 0) return;
    hanoi3(n - 1, from, to, via);
    move_count++;
    printf("  move %2d: disk %d  %c -> %c\n", move_count, n, from, to);
    hanoi3(n - 1, via, from, to);
}

void frame_stewart(int n, char a, char b, char c, char d) {
    if (n == 0) return;
    if (n == 1) {
        move_count++;
        printf("  move %2d: disk %d  %c -> %c\n", move_count, n, a, d);
        return;
    }
    int k = split_k[n];
    frame_stewart(k, a, b, d, c);
    hanoi3(n - k, a, b, d);
    frame_stewart(k, c, a, b, d);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    build_frame_stewart(n);

    printf("\nMinimum number of moves for %d disks on 4 pegs: %lld\n", n, t4[n]);

    printf("\nFull move sequence (pegs A, B, C, D; A = source, D = target):\n");
    frame_stewart(n, 'A', 'B', 'C', 'D');
    printf("\nTotal moves printed: %d\n", move_count);

    free(t4);
    free(split_k);
    return 0;
}
