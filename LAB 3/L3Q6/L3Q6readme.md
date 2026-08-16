# Q6 - Use of Loop Invariants in Sorting (Selection Sort)

## Files
- `L3Q6.c` - the program
- `L3Q6-algorithm.md` - pseudocode
- `L3Q6readme.md` - this file
- `L3Q6.PNG` - graph of comparisons used against `n`, compared to `n(n-1)/2`

## The Loop Invariant
**Invariant:** At the start of each iteration of the outer loop (indexed by
`i`), the sub-array `A[0..i-1]` contains the `i` smallest elements of the
original array, in sorted (ascending) order.

### Initialization
Before the first iteration, `i = 0`, so `A[0..i-1]` is the empty sub-array.
An empty sub-array trivially satisfies "the smallest 0 elements, sorted" —
the invariant holds vacuously.

### Maintenance
Assume the invariant holds at the start of iteration `i`. The inner loop
scans `A[i..n-1]` and finds the index `m` of the minimum value in that
range. Swapping `A[i]` and `A[m]` places this minimum — the `(i+1)`-th
smallest element overall — right after the already-sorted `A[0..i-1]`.
Thus `A[0..i]` now holds the `i+1` smallest elements, sorted, so the
invariant holds at the start of iteration `i+1`.

### Termination
The outer loop runs for `i = 0, 1, ..., n-2` and terminates at `i = n-1`.
At that point the invariant states `A[0..n-2]` holds the `n-1` smallest
elements, sorted. The one element left, `A[n-1]`, must then be the single
largest element, already in its correct place — so `A[0..n-1]` is fully
sorted, as required.

## Why only the first (n − 1) elements
Once `A[0..n-2]` holds the `n-1` smallest elements in order, the remaining
element `A[n-1]` is forced to be the maximum — there is nothing left to
compare it against or swap it with. Running the outer loop for `i = n-1`
would leave the inner loop scanning an empty range (`j = n .. n-1`), a
wasted iteration. The invariant guarantees correctness as soon as `i = n-1`
is reached, so processing it is unnecessary.

## Mathematical Calculation of Running Time
For each `i = 0, 1, ..., n-2`, the inner loop performs `(n - 1 - i)`
comparisons to find the minimum of the unsorted suffix, regardless of the
input's order:

  Total comparisons = Σ (i = 0 to n-2) (n - 1 - i)
                     = (n-1) + (n-2) + ... + 1
                     = n(n-1) / 2          [sum of the first (n-1) positive integers]
                     = Θ(n²)

Since this count does not depend on how the elements are arranged — the
inner loop always scans the entire remaining unsorted suffix, even if it is
already sorted — the best case and worst case coincide:

  Best case = Worst case = Θ(n²)

Selection sort is therefore **not adaptive**: it gains no speedup from a
nearly-sorted or already-sorted input, unlike e.g. insertion sort.

## Conclusion
The loop invariant "`A[0..i-1]` holds the `i` smallest elements, sorted"
cleanly proves selection sort correct via the standard three-part argument
(initialization, maintenance, termination), and also explains why the outer
loop only needs `n - 1` iterations rather than `n`. Because the algorithm
always performs a full linear scan to find each successive minimum
regardless of input order, its best-case and worst-case running times
coincide at `Θ(n²)` — the implementation's measured comparison count
(`n(n-1)/2`) confirms this for every input tested, sorted or not.