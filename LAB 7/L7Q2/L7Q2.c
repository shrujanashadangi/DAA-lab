/* DAA Lab 07 - Q2: Super egg testing experiment
 * Reads the number of eggs and floors and finds the minimum number of
 * trials needed, in the worst case, using dynamic programming.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int eggs, floors;
    printf("Enter number of eggs: ");
    if (scanf("%d", &eggs) != 1 || eggs <= 0) return 1;
    printf("Enter number of floors: ");
    if (scanf("%d", &floors) != 1 || floors < 0) return 1;

    int **dp = malloc((eggs + 1) * sizeof(int *));
    for (int i = 0; i <= eggs; i++) dp[i] = malloc((floors + 1) * sizeof(int));

    for (int j = 0; j <= floors; j++) dp[1][j] = j;
    for (int i = 0; i <= eggs; i++) {
        dp[i][0] = 0;
        if (floors >= 1) dp[i][1] = 1;
    }

    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            int best = j;
            for (int x = 1; x <= j; x++) {
                int breaks = dp[i - 1][x - 1];
                int survives = dp[i][j - x];
                int worst = breaks > survives ? breaks : survives;
                if (worst + 1 < best) best = worst + 1;
            }
            dp[i][j] = best;
        }
    }

    printf("\nMinimum number of trials needed with %d egg(s) and %d floor(s): %d\n",
           eggs, floors, dp[eggs][floors]);

    printf("\nTable of dp[eggs][floors] (trials needed):\n     ");
    for (int j = 0; j <= floors; j++) printf("%4d", j);
    printf("\n");
    for (int i = 1; i <= eggs; i++) {
        printf("e=%2d", i);
        for (int j = 0; j <= floors; j++) printf("%4d", dp[i][j]);
        printf("\n");
    }

    for (int i = 0; i <= eggs; i++) free(dp[i]);
    free(dp);
    return 0;
}
