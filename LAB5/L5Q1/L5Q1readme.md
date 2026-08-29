# Q1 - Find the Median without Sorting

## Files
- `L5Q1.c` - the program
- `L5Q1-algorithm.md` - pseudocode
- `L5Q1readme.md` - this file

## Mathematical Calculation of Time Complexity
Let `T(n)` be the number of comparisons Quickselect makes to find the
median of `n` elements. A random pivot splits the array roughly in
half on average, and we only ever recurse into the half that still
contains the rank we're looking for, so:

  T(n) = T(n/2) + c·n   for n > 1
  T(1) = 0

Unrolling it:

  T(n) = T(n/2) + c·n
       = T(n/4) + c·n/2 + c·n
       = T(n/8) + c·n/4 + c·n/2 + c·n
       = ...
       = T(1) + c·n·(1 + 1/2 + 1/4 + ... + 1/2^(k-1)),  where n/2^k = 1

`1 + 1/2 + 1/4 + ...` is a geometric series that converges to 2, so the
worst that leaves us with is:

  T(n) ≤ 2·c·n  ⇒  T(n) = O(n) on average

which is really the whole point of the question: avoid paying
`O(n log n)` just to read off one middle value.

If the pivot keeps getting unlucky (always picks the smallest/largest
element left, e.g. a carefully crafted adversarial input), nothing
gets discarded each round and it degrades to:

  T(n) = T(n-1) + c·n
       = c·(n + (n-1) + ... + 1)
       = c·n·(n+1)/2  ⇒  O(n²)

## Conclusion
Quickselect only chases down the half of the array where the median
could possibly be, instead of sorting the whole thing or scanning both
halves the way Quicksort does. That's what keeps it at average `O(n)`.
Running it on random test data and tracking the comparison counts
shows the numbers scaling fairly closely with `n` as it grows. The
`O(n²)` worst case is real on paper but doesn't show up unless someone
deliberately feeds it bad input.
