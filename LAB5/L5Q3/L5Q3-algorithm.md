# L5Q3-algorithm

## Aim
Generate n random elements, store them in a file, and sort them using
Quicksort.

## Algorithm
1. Start.
2. Generate n random numbers and write them to input.txt.
3. Read the n numbers back from input.txt into an array.
4. Sort the array using Quicksort:
   a. If the sub-array has more than one element, pick a pivot (last
      element).
   b. Partition the sub-array so elements ≤ pivot move left and
      elements > pivot move right; the pivot lands at its final
      sorted index p.
   c. Recursively apply Quicksort to the left part (low .. p-1) and
      the right part (p+1 .. high).
5. Write the sorted array to output.txt.
6. Stop.

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

procedure QUICKSORT(A, low, high)
    if low < high
        p ← PARTITION(A, low, high)
        QUICKSORT(A, low, p-1)
        QUICKSORT(A, p+1, high)
```

### Time Complexity
- Best/Average case: O(n log n)
- Worst case: O(n²), e.g. already-sorted input with last-element
  pivoting, where partitions become as unbalanced as possible.
