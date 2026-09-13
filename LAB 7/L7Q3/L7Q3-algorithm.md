# L7Q3-algorithm

## Aim
Move n disks from one peg to another using 4 pegs instead of the usual
3, in the minimum number of moves, and confirm that 8 disks takes 33
moves.

## Algorithm
1. Start.
2. T3(m) = 2^m - 1 (ordinary 3-peg Hanoi).
3. T4(1) = 1.
4. For n >= 2, try every split k from 1 to n-1: move top k disks with
   the 4-peg method, move remaining n-k disks with 3-peg Hanoi, move
   the k disks back with the 4-peg method.
5. T4(n) = min over k of 2*T4(k) + T3(n-k). Store the best k.
6. To print the moves, repeat the same split recursively.
7. Stop.

## Pseudocode

```
procedure BUILD_T4(n)
    T4[0] <- 0, T4[1] <- 1
    for m <- 2 to n
        best <- infinity
        for k <- 1 to m-1
            cost <- 2*T4[k] + (2^(m-k) - 1)
            if cost < best
                best <- cost
                split[m] <- k
        T4[m] <- best

procedure HANOI3(n, from, via, to)
    if n = 0: return
    HANOI3(n-1, from, to, via)
    print "move disk n: from -> to"
    HANOI3(n-1, via, from, to)

procedure FRAME_STEWART(n, a, b, c, d)
    if n = 0: return
    if n = 1
        print "move disk 1: a -> d"
        return
    k <- split[n]
    FRAME_STEWART(k, a, b, d, c)
    HANOI3(n-k, a, b, d)
    FRAME_STEWART(k, c, a, b, d)
```

## Time Complexity
O(n^2) to build the T4 table, O(T4(n)) to print the moves.
