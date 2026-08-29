# L5Q4-algorithm

## Aim
Generate n random elements, store them in a file, and sort them using
Heap Sort.

## Algorithm
1. Start.
2. Generate n random numbers and write them to input2.txt.
3. Read the n numbers back from input2.txt into an array.
4. Build a max heap out of the array: for every non-leaf node, from
   the last one up to the root, sift it down so the max-heap property
   (parent ≥ children) holds.
5. Repeat n-1 times:
   a. Swap the root (current maximum) with the last element of the
      active heap.
   b. Shrink the heap size by 1 (the swapped-out max is now in its
      final sorted position).
   c. Sift the new root down to restore the max-heap property.
6. The array is now sorted in ascending order. Write it to output2.txt.
7. Stop.

## Pseudocode

```
procedure HEAPIFY(A, n, i)
    largest ← i
    left ← 2i + 1
    right ← 2i + 2
    if left < n and A[left] > A[largest]
        largest ← left
    if right < n and A[right] > A[largest]
        largest ← right
    if largest ≠ i
        SWAP(A[i], A[largest])
        HEAPIFY(A, n, largest)

procedure HEAPSORT(A[0..n-1])
    for i ← n/2 - 1 downto 0
        HEAPIFY(A, n, i)
    for i ← n-1 downto 1
        SWAP(A[0], A[i])
        HEAPIFY(A, i, 0)
```

### Time Complexity
- Building the heap: O(n)
- n extractions, each with an O(log n) sift-down: O(n log n)
- Total: O(n log n) in the best, average, and worst case alike.
