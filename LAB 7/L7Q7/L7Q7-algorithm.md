# L7Q7-algorithm

## Aim
Given a chain of n matrices, find the parenthesization that minimizes
the total number of scalar multiplications needed to compute the
product.

## Algorithm
1. Start.
2. A_i has dimensions p[i-1] x p[i].
3. m[i][i] = 0.
4. For a chain A_i..A_j, try every split k from i to j-1:
   m[i][j] = min over k of m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j].
5. Store the best k in s[i][j].
6. m[1][n] is the answer. Reconstruct the parenthesization from s.
7. Stop.

## Pseudocode

```
procedure MCM(p, n)
    for i <- 1 to n
        m[i][i] <- 0
    for len <- 2 to n
        for i <- 1 to n-len+1
            j <- i + len - 1
            m[i][j] <- infinity
            for k <- i to j-1
                cost <- m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if cost < m[i][j]
                    m[i][j] <- cost
                    s[i][j] <- k
    return m[1][n], s

procedure PRINT_PARENS(i, j, s)
    if i = j
        print "A" + i
        return
    print "("
    PRINT_PARENS(i, s[i][j], s)
    PRINT_PARENS(s[i][j]+1, j, s)
    print ")"
```

## Time Complexity
O(n^3) time, O(n^2) space.
