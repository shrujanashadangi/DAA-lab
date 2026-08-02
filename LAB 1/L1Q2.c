/*
 * DAA Lab: Question 2 -- Fair vs Biased Coin
 * Simulate tossing a fair coin many times and show that the fraction
 * of heads comes out close to 0.5. Then do the same for a biased coin.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int N;
    double p;

    printf("Enter the number of times to toss the coin: ");
    scanf("%d", &N);

    printf("Enter the probability of heads for the biased coin (e.g. 0.7): ");
    scanf("%lf", &p);

    if (N <= 0) {
        printf("Number of tosses must be positive.\n");
        return 1;
    }
    if (p < 0.0 || p > 1.0) {
        printf("Probability must be between 0 and 1.\n");
        return 1;
    }

    int hf = 0, hb = 0;

    for (int i = 0; i < N; i++) {
        double r1 = (double) rand() / RAND_MAX;
        double r2 = (double) rand() / RAND_MAX;

        if (r1 < 0.5) hf++;          // fair coin toss
        if (r2 < p) hb++;    // biased coin toss
    }

    printf("\n--- Results after %d tosses ---\n", N);
    printf("Fair coin (p = 0.5):    %d heads  ->  fraction = %.4f\n",
           hf, (double) hf / N);
    printf("Biased coin (p = %.2f): %d heads  ->  fraction = %.4f\n",
           p, hb, (double) hb / N);

    printf("\nThe fair coin's fraction is close to 0.5\n");
    printf("The biased coin's fraction is close to %.2f.\n", p);

    return 0;
}
