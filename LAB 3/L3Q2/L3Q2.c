// DAA Lab 03 - Q2: Search the Defective Coin

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int wc;

int weigh(int w[], int l1, int l2, int k) {
    wc++;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < k; i++) {
        s1 += w[l1 + i];
        s2 += w[l2 + i];
    }
    if (s1 < s2) return -1;
    if (s1 > s2) return 1;
    return 0;
}

int findFake(int w[], int lo, int hi, int ref) {
    int n = hi - lo + 1;

    if (n == 1) {
        if (ref == -1) return -1;
        wc++;
        return (w[lo] < w[ref]) ? lo : -1;
    }

    int half = n / 2;
    int l = lo, r = lo + half;
    int res = weigh(w, l, r, half);

    if (res == 0) {
        if (n % 2 == 1) {
            int left = lo + 2 * half;
            int rf = (ref != -1) ? ref : l;
            wc++;
            return (w[left] < w[rf]) ? left : -1;
        }
        return -1;
    } else if (res == -1) {
        return findFake(w, l, l + half - 1, r);
    } else {
        return findFake(w, r, r + half - 1, l);
    }
}

int isValidCoinSet(int w[], int n) {
    if (n <= 1) return 1;

    int standard_weight;
    if (n >= 3) {
        if (w[0] == w[1] || w[0] == w[2]) standard_weight = w[0];
        else standard_weight = w[1];
    } else {
        standard_weight = (w[0] > w[1]) ? w[0] : w[1];
    }

    int lighter_count = 0;

    for (int i = 0; i < n; i++) {
        if (w[i] > standard_weight) return 0;
        if (w[i] < standard_weight) {
            lighter_count++;
            if (lighter_count > 1) return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;
    printf("Enter number of coins: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *w = (int *)malloc(sizeof(int) * n);
    if (!w) return 1;

    do {
        printf("Enter weight of %d coins (all identical, at most ONE lighter):\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }

        if (!isValidCoinSet(w, n)) {
            printf("Error: Invalid coin weights. Ensure (n - 1) coins have identical weight and at most one is lighter. Try again.\n\n");
        }
    } while (!isValidCoinSet(w, n));

    wc = 0;
    int pos = findFake(w, 0, n - 1, -1);

    if (pos != -1)
        printf("\nDefective (lighter) coin is at index %d (Weight: %d)\n", pos, w[pos]);
    else
        printf("\nNo defective coin - all coins weigh the same.\n");

    printf("Weighings used = %d\n", wc);
    printf("log2(n) = %.2f\n", log2((double)n));

    free(w);
    return 0;
}
