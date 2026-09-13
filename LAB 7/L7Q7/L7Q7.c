/* DAA Lab 07 - Q7: Matrix Chain Multiplication
 * Reads the dimensions of a chain of matrices and finds the minimum
 * number of scalar multiplications, with the optimal parenthesization.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **m, **s;
int *p;
int n;

void print_parens(int i, int j) {
    if (i == j) { printf("A%d", i); return; }
    printf("(");
    print_parens(i, s[i][j]);
    print_parens(s[i][j] + 1, j);
    printf(")");
}

int main() {
    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    p = malloc((n + 1) * sizeof(int));
    printf("Enter the %d dimensions (matrix i is p[i-1] x p[i]):\n", n + 1);
    for (int i = 0; i <= n; i++) {
        printf("  p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    m = malloc((n + 1) * sizeof(int *));
    s = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        m[i] = calloc(n + 1, sizeof(int));
        s[i] = calloc(n + 1, sizeof(int));
    }

    for (int i = 1; i <= n; i++) m[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                long long cost = (long long)m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = (int)cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    print_parens(1, n);
    printf("\n");

    printf("\nFull m[i][j] table (min cost to multiply A_i..A_j):\n     ");
    for (int j = 1; j <= n; j++) printf("%8d", j);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("i=%2d", i);
        for (int j = 1; j <= n; j++) {
            if (j < i) printf("        ");
            else printf("%8d", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i <= n; i++) { free(m[i]); free(s[i]); }
    free(m);
    free(s);
    free(p);
    return 0;
}
