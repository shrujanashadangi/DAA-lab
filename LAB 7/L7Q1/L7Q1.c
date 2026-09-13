/* DAA Lab 07 - Q1: Invert the coin-triangle
 * Reads the number of rows n and finds the minimum number of coins
 * that must move to flip an n-row triangle upside down, then prints
 * one valid set of moves.
 */

#include <stdio.h>
#include <stdlib.h>

int **make_grid(int rows, int width) {
    int **g = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) g[i] = calloc(width, sizeof(int));
    return g;
}

void free_grid(int **g, int rows) {
    for (int i = 0; i < rows; i++) free(g[i]);
    free(g);
}

int overlap_for(int n, int dy, int dx2, int rows, int width, int offset) {
    int **grid = make_grid(rows, width);
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++) {
            int x2 = 2 * c - r, y = r;
            int tx2 = -x2 + dx2;
            int ty = (n - 1 - y) + dy;
            if (ty >= 0 && ty < rows && tx2 + offset >= 0 && tx2 + offset < width)
                grid[ty][tx2 + offset] = 1;
        }
    int stay = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++) {
            int x2 = 2 * c - r;
            if (grid[r][x2 + offset]) stay++;
        }
    free_grid(grid, rows);
    return stay;
}

int main() {
    int n;
    printf("Enter number of rows of the coin triangle: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int total = n * (n + 1) / 2;
    int rows = 2 * n + 5;
    int width = 4 * n + 10;
    int offset = 2 * n + 5;

    int best = -1, best_dy = 0, best_dx = 0;
    for (int dy = 0; dy <= n; dy++)
        for (int dx2 = -1; dx2 <= 0; dx2++) {
            int s = overlap_for(n, dy, dx2, rows, width, offset);
            if (s > best) { best = s; best_dy = dy; best_dx = dx2; }
        }

    int moves = total - best;
    int formula = (n * (n + 1)) / 6;

    printf("\nTotal coins             : %d\n", total);
    printf("Coins that stay put     : %d\n", best);
    printf("Minimum coins to move   : %d\n", moves);
    printf("Closed-form check       : floor(n*(n+1)/6) = %d\n", formula);

    int **grid = make_grid(rows, width);
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++) {
            int x2 = 2 * c - r, y = r;
            int tx2 = -x2 + best_dx;
            int ty = (n - 1 - y) + best_dy;
            grid[ty][tx2 + offset] = 1;
        }

    int **covered = make_grid(rows, width);
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++) {
            int x2 = 2 * c - r;
            covered[r][x2 + offset] = 1;
        }

    int (*src)[2] = malloc(moves * sizeof(*src));
    int src_count = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c <= r; c++) {
            int x2 = 2 * c - r;
            if (!grid[r][x2 + offset]) { src[src_count][0] = r; src[src_count][1] = c; src_count++; }
        }

    int (*dst)[2] = malloc(moves * sizeof(*dst));
    int dst_count = 0;
    for (int y = 0; y < rows && dst_count < moves; y++)
        for (int k = 0; k < width && dst_count < moves; k++) {
            if (grid[y][k] && !covered[y][k]) {
                dst[dst_count][0] = y; dst[dst_count][1] = k - offset; dst_count++;
            }
        }

    printf("\nOne valid set of moves:\n");
    printf("(source: 1-indexed row/pos in the original triangle)\n");
    printf("(target: lattice cell y,x in the flipped copy, same units)\n");
    for (int i = 0; i < moves && i < dst_count; i++)
        printf("  source row %d pos %d  ->  target cell (y=%d, x=%d)\n",
               src[i][0] + 1, src[i][1] + 1, dst[i][0], dst[i][1]);

    free_grid(grid, rows);
    free_grid(covered, rows);
    free(src);
    free(dst);
    return 0;
}
