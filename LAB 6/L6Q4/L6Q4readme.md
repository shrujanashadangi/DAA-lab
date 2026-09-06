# Q4 - Sorting via reversal procedure

## Files
- `L6Q4.c` - the program
- `L6Q4-algorithm.md` - proof sketch (Part 1) and the rotation-based merge algorithm (Part 2)
- `L6Q4readme.md` - this file

## What the program does
Takes a permutation of `1..n` and sorts it using a merge-sort structure
where the merge step is done entirely with `reverse()` calls (via a
3-reversal rotate trick), rather than by copying into a temporary array.
It tracks and prints the total number of reversals used and the total
cost (sum of every reversal's length), so the result can be checked
against the O(n log^2 n) bound directly.

## Input representation
The permutation is stored as a plain `int` array, since the only
operation allowed on it (reversal of a contiguous range) works directly
on array indices - no extra structure needed.

## Mathematical Calculation of Time Complexity
Merge sort's recursion has `O(log n)` levels. At each level, the
elements being merged sum to `n` across all the merge calls at that
level. Within each merge, a binary search locates each out-of-place
block in `O(log n)` time, and each rotate then costs `O(block size)`
reversal-cost. Summed over one full level, this comes out to about
`O(n log n)` cost for that level. Multiplying by the `O(log n)` levels
of the recursion gives:

  Total cost = O(n log n) x O(log n) = O(n log^2 n)

which is the bound the question asks for.

## Conclusion
The naive selection-sort-by-reversal approach (Part 1's proof) uses only
O(n) reversal calls, but can rack up O(n^2) total cost if those
reversals happen to be long. Restructuring the sort around merge sort's
divide and conquer shape, and doing each merge with binary-search-guided
rotations instead of one-element-at-a-time shuffles, brings the total
cost down to O(n log^2 n). This was verified on a random 100-element
permutation, which sorted correctly with a total reversal cost of 3430 -
comfortably under the 4414 reference bound computed for the same n.
