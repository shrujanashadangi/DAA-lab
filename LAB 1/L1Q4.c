// DAA Lab - Towers of Hanoi
// move n discs from A to C using B as spare, one at a time
// enter n, see the moves (if small enough) and the total count

#include <stdio.h>

int moves = 0;

void hanoi(int n, char from, char to, char aux, int show) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to, show);

    moves++;
    if (show) {
        printf("Move disc %d from %c to %c\n", n, from, to);
    }

    hanoi(n - 1, aux, to, from, show);
}

int main() {
    int n;

    printf("Enter number of discs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n should be positive.\n");
        return 1;
    }

    moves = 0;

    if (n <= 10) {

        printf("\nMoves:\n");
        hanoi(n, 'A', 'C', 'B', 1);
    } else {
        printf("\n%d discs is too many to print every move, just counting them...\n", n);
        hanoi(n, 'A', 'C', 'B', 0);
    }

    printf("\nTotal moves for %d discs = %d\n", n, moves);

    return 0;
}
