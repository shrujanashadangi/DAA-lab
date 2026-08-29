# L5Q2-algorithm

## Aim
Given a list of n numbers and an integer k, find the k'th smallest
element without sorting the list, in average O(n) time.

## Algorithm
1. Start.
2. Pick a pivot (last element of the current sub-array).
3. Partition the sub-array so elements ≤ pivot move left and elements
   > pivot move right; the pivot lands at its final sorted position,
   with rank `pos` (1-based) within the current sub-array.
4. Compare `pos` with k:
   a. If pos = k, the pivot is the k'th smallest element. Stop.
   b. If k < pos, recurse into the left part with the same k.
   c. If k > pos, recurse into the right part looking for the
      (k - pos)'th smallest element there.
5. Stop when the answer is found.

## Pseudocode

```
procedure PARTITION(A, low, high)
    pivot ← A[high]
    i ← low - 1
    for j ← low to high - 1
        if A[j] ≤ pivot
            i ← i + 1
            SWAP(A[i], A[j])
    SWAP(A[i+1], A[high])
    return i + 1

procedure QUICKSELECT(A, low, high, k)      // k is 1-based
    if low = high
        return A[low]
    p ← PARTITION(A, low, high)
    pos ← p - low + 1
    if pos = k
        return A[p]
    else if k < pos
        return QUICKSELECT(A, low, p-1, k)
    else
        return QUICKSELECT(A, p+1, high, k - pos)
```

### Time Complexity
- Average case: O(n), since each partition step discards the half of
  the array that cannot contain the k'th element.
- Worst case: O(n²), if the pivot is always the smallest or largest
  remaining element.
