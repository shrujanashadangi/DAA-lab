# L7Q1-algorithm

## Aim
Invert an n-row triangle of coins (apex up) into an apex-down triangle
using the smallest possible number of coin moves, and give a compact
formula for that number.

## Algorithm
1. Start.
2. Assign each coin integer coordinates (row, position).
3. For a range of shifts (dy, dx2), overlay the flipped triangle on
   the original and count how many coins land on their own position.
4. Keep the shift that gives the largest overlap.
5. moves = total coins - best overlap.
6. Pair every uncovered original coin with an uncovered target cell to
   get the move list.
7. Stop.

## Pseudocode

```
procedure OVERLAP(n, dy, dx2)
    mark every coin position (x2, y) transformed by
        x2' <- -x2 + dx2
        y'  <- (n-1-y) + dy
    stay <- 0
    for every original coin (x2, y)
        if (x2, y) is marked
            stay <- stay + 1
    return stay

procedure INVERT_TRIANGLE(n)
    total <- n(n+1)/2
    best <- 0
    for dy <- 0 to n
        for dx2 <- -1 to 0
            best <- max(best, OVERLAP(n, dy, dx2))
    moves <- total - best
    build the move list by pairing every uncovered original coin
        with an uncovered target cell under the best shift
    return moves
```

## Time Complexity
O(n^3) time, O(n^2) space.
