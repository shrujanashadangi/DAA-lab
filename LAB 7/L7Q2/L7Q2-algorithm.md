# L7Q2-algorithm

## Aim
Find the minimum number of egg drops needed, in the worst case, to
determine the highest floor from which an egg survives, given E eggs
and F floors.

## Algorithm
1. Start.
2. dp[i][j] = minimum trials with i eggs and j floors.
3. dp[1][j] = j.
4. For i >= 2, try every floor x from 1 to j.
5. If the egg breaks: reduces to dp[i-1][x-1]. If it survives: reduces
   to dp[i][j-x].
6. dp[i][j] = 1 + min over x of max(dp[i-1][x-1], dp[i][j-x]).
7. dp[E][F] is the answer.
8. Stop.

## Pseudocode

```
procedure MIN_TRIALS(E, F)
    for j <- 0 to F
        dp[1][j] <- j
    for i <- 1 to E
        dp[i][0] <- 0
        dp[i][1] <- 1
    for i <- 2 to E
        for j <- 2 to F
            best <- j
            for x <- 1 to j
                breaks   <- dp[i-1][x-1]
                survives <- dp[i][j-x]
                worst <- max(breaks, survives)
                best <- min(best, 1 + worst)
            dp[i][j] <- best
    return dp[E][F]
```

## Time Complexity
O(E * F^2) time, O(E * F) space.
