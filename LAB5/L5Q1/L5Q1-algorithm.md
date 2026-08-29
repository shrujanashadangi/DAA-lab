# L5Q1-algorithm

## Aim
Given a list of n numbers, find the median without sorting the list, in
average O(n) time.

## Algorithm
1. Start.
2. If n is odd, the median is the element that would sit at index n/2
   (0-based) in the sorted list — the ⌊n/2⌋-th smallest element.
3. If n is even, the median is the average of the elements at indices
   n/2 - 1 and n/2 in the sorted list.
4. To find the element at a given rank without sorting, use Quickselect:
   a. Pick a pivot (last element of the current sub-array).
   b. Partition the sub-array so smaller elements move left, larger
      elements move right; the pivot lands at its final sorted index p.
   c. If p equals the target rank, the pivot is the answer.
   d. If p is greater than the target rank, recurse into the left part.
   e. If p is smaller than the target rank, recurse into the right part.
5. Stop.

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

procedure QUICKSELECT(A, low, high, k)
    if low = high
        return A[low]
    p ← PARTITION(A, low, high)
    if p = k
        return A[p]
    else if k < p
        return QUICKSELECT(A, low, p-1, k)
    else
        return QUICKSELECT(A, p+1, high, k)

procedure MEDIAN(A[0..n-1])
    if n is odd
        return QUICKSELECT(A, 0, n-1, n/2)
    else
        left  ← QUICKSELECT(A, 0, n-1, n/2 - 1)
        right ← QUICKSELECT(A, 0, n-1, n/2)
        return (left + right) / 2
```

### Time Complexity
- Average case: O(n), since each partition step throws away half the
  remaining elements: T(n) = T(n/2) + O(n).
- Worst case: O(n²), if the pivot chosen is always the smallest or
  largest remaining element (e.g. already sorted input).
