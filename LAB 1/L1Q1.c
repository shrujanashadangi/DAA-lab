/*
 * DAA Lab: Question 1 -- Put them in order
 * Given 12 functions, arrange them in increasing order of growth
 * for a (user-entered) sufficiently large value of n.
 *
 * Method: compute log2(f(n)) for each function (this avoids overflow
 * for huge values like 3^n), then sort by that.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[30];
    double val;
} Func;

int cmp(const void *a, const void *b) {
    double diff = ((Func *)a)->val - ((Func *)b)->val;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    double n;

    printf("Enter a sufficiently large value of n (e.g. 100000): ");
    scanf("%lf", &n);

    if (n <= 1) {
        printf("Please enter a value of n greater than 1.\n");
        return 1;
    }

    double log2n = log2(n);

    Func f[12];

    strcpy(f[0].name,  "1/n");            f[0].val  = -log2n;
    strcpy(f[1].name,  "log2(n)");        f[1].val  = log2(log2n);
    strcpy(f[2].name,  "12*sqrt(n)");     f[2].val  = log2(12) + 0.5*log2n;
    strcpy(f[3].name,  "50*n^0.5");       f[3].val  = log2(50) + 0.5*log2n;
    strcpy(f[4].name,  "n^0.51");         f[4].val  = 0.51*log2n;
    strcpy(f[5].name,  "2^32 * n");       f[5].val  = 32 + log2n;
    strcpy(f[6].name,  "n*log2(n)");      f[6].val  = log2n + log2(log2n);
    strcpy(f[7].name,  "n^2 - 324");      f[7].val  = log2(n*n - 324);
    strcpy(f[8].name,  "100n^2 + 6n");    f[8].val  = log2(100*n*n + 6*n);
    strcpy(f[9].name,  "2*n^3");          f[9].val  = log2(2) + 3*log2n;
    strcpy(f[10].name, "n^(log2 n)");     f[10].val = log2n * log2n;
    strcpy(f[11].name, "3^n");            f[11].val = n * log2(3);

    qsort(f, 12, sizeof(Func), cmp);

    printf("\nIncreasing order of growth for n = %.0f:\n\n", n);
    for (int i = 0; i < 12; i++) {
        printf("%2d. %s\n", i + 1, f[i].name);
    }

    return 0;
}
