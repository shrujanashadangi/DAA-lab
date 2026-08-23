# L4Q2-algorithm

## Aim
Given two sets S1 and S2 (each of size n) and a number x, determine
whether some a in S1 and b in S2 add up to x, in O(n log n) time.

## Algorithm
1. Start.
2. Sort the set S2.
3. For each element a in S1, compute the value needed as x minus a.
4. Binary search the sorted S2 for this needed value.
5. If found, report the pair (a, needed value) and stop searching.
6. If no element of S1 finds a match, report that no such pair exists.
7. Stop.

## Pseudocode

```
procedure PAIR-SUM-EXISTS(S1[0..n-1], S2[0..n-1], x)
    B ← SORT(S2)

    for i ← 0 to n-1
        need ← x - S1[i]
        if BINARY-SEARCH(B, need) = TRUE
            return (S1[i], need)
        end if
    end for

    return NIL
end procedure

procedure BINARY-SEARCH(A[0..m-1], target)
    lo ← 0
    hi ← m-1
    while lo ≤ hi
        mid ← ⌊(lo + hi) / 2⌋
        if A[mid] = target
            return TRUE
        else if A[mid] < target
            lo ← mid + 1
        else
            hi ← mid - 1
        end if
    end while
    return FALSE
end procedure
```

### Time Complexity
O(n log n)
