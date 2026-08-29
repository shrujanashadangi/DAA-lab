# Q4 - Heap Sort on N Randomly Generated Elements Stored in a File

## Files
- `L5Q4.c` - the program
- `L5Q4-algorithm.md` - pseudocode
- `L5Q4readme.md` - this file

## Mathematical Calculation of Time Complexity
**Building the heap.** A node sitting at height `h` needs at most
`O(h)` comparisons to sift down, and there are at most `⌈n/2^(h+1)⌉`
such nodes. Adding this up across all levels:

  Cost = Σ (h = 0 to log2 n)  ⌈n/2^(h+1)⌉ · O(h)
       = O(n) · Σ (h / 2^h)

`Σ h/2^h` (summed to infinity) converges to a constant, `2`, so the
build-heap step comes out to just:

  Build-heap cost = O(n)

which is a bit surprising the first time you see it. Heapify alone
looks like `O(log n)` per call, but most nodes are near the bottom of
the tree where sifting barely does anything, so it averages out to
linear overall.

**Extracting the max n times.** Each extraction swaps the root to the
end and sifts the new root down a heap of height at most `log2(n)`:

  Extraction cost = n · O(log n) = O(n log n)

**Putting it together:**

  T(n) = O(n) + O(n log n) = O(n log n)

And this bound holds no matter what the input looks like, since sifting a
heap of size `m` always costs `O(log m)` regardless of the actual
values, so there's no "bad input" that can push Heap Sort into
quadratic territory the way there is for Quicksort.

## Conclusion
Heap Sort's `O(n log n)` bound applies in the best, average, and worst
case alike, since it only depends on the height of the heap and not on
how the input values happen to be arranged. Measuring the comparison
counts as `n` grows tracks the `n log n` curve closely, which lines up
with the analysis above.
