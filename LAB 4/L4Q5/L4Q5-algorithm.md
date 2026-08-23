# L4Q5-algorithm

## Aim
Given a list I of n intervals, merge all overlapping intervals, in
worst-case O(n log n) time.

## Algorithm
1. Start.
2. Sort the intervals by their starting value.
3. Take the first interval as the current interval.
4. For each remaining interval, check if it starts before or exactly at
   the end of the current interval.
5. If it does, merge it into the current interval by extending its end
   if needed.
6. If it does not, close off the current interval by adding it to the
   result, then start a new current interval from this one.
7. After the loop ends, add the last current interval to the result.
8. Stop.

## Pseudocode

```
procedure MERGE-INTERVALS(I[0..n-1])
    A ← SORT(I) by start value
    M ← empty list
    cur ← A[0]

    for i ← 1 to n-1
        if A[i].start ≤ cur.end
            cur.end ← max(cur.end, A[i].end)
        else
            APPEND(M, cur)
            cur ← A[i]
        end if
    end for

    APPEND(M, cur)
    return M
end procedure
```

### Time Complexity
O(n log n)
