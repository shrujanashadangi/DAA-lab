# L3Q6-algorithm

## Aim
Sort `n` numbers stored in `A[0..n-1]` by repeatedly finding the smallest
element of the unsorted suffix and swapping it into place, and analyze the
loop invariant that proves this algorithm (Selection Sort) correct.

---

## Algorithm — `SelectionSort(A, n)`
1. Start.
2. For `i = 0` to `n - 2`, repeat steps 3-5.
3. Assume the element currently at position `i` is the smallest of the
   unsorted remainder; let `m = i`.
4. For each `j = i + 1` to `n - 1`, compare `A[j]` with `A[m]`; whenever
   `A[j]` is smaller, update `m = j` to remember the new smallest index.
5. If `m` turned out to be different from `i`, swap `A[i]` and `A[m]`,
   placing the smallest element of `A[i..n-1]` into position `i`.
6. Once the outer loop finishes, `A[0..n-1]` is sorted — stop.

### Time Complexity
Both loops run regardless of the input's initial order — the algorithm
always performs the same number of comparisons:

  Comparisons = (n-1) + (n-2) + ... + 1 = n(n-1)/2 = Θ(n²)

**Worst case:** Θ(n²)
**Best case:** Θ(n²) — selection sort is *not* adaptive; even an already
sorted array is fully scanned to find each successive minimum, so the best
case is no better than the worst case.
