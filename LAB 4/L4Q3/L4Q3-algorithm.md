# L4Q3-algorithm

## Aim
Given a set S of n integers and integer T, test whether k elements of S
add up to T, in O(n^(k-1) log n) time.

## Algorithm
1. Start.
2. Sort the set S.
3. Fix the first k-2 elements one at a time using nested loops, always
   choosing indices in increasing order so no index is reused.
4. For the two positions left, scan through the remaining elements, and
   for each one binary search for the exact complement needed to reach
   the remaining target.
5. If such a pair is found, report all k numbers together.
6. If no combination of k numbers adds up to T, report that none exists.
7. Stop.

## Pseudocode

```
procedure K-SUM-EXISTS(S[0..n-1], k, T)
    A ← SORT(S)
    return FIND-K(A, 0, k, T)
end procedure

procedure FIND-K(A, start, k, rem)
    if k = 2
        return TWO-SUM(A, start, rem)
    end if

    for i ← start to length(A) - k
        if FIND-K(A, i+1, k-1, rem - A[i]) = TRUE
            OUTPUT(A[i])
            return TRUE
        end if
    end for

    return FALSE
end procedure

procedure TWO-SUM(A, start, rem)
    for i ← start to length(A) - 1
        need ← rem - A[i]
        j ← BINARY-SEARCH-INDEX(A, i+1, length(A)-1, need)
        if j ≠ NIL
            OUTPUT(A[i], A[j])
            return TRUE
        end if
    end for
    return FALSE
end procedure
```

### Time Complexity
O(n^(k-1) log n)
