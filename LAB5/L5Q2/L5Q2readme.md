# Q2 - Find the K'th Smallest Element without Sorting

## Files
- `L5Q2.c` - the program
- `L5Q2-algorithm.md` - pseudocode
- `L5Q2readme.md` - this file

## Mathematical Calculation of Time Complexity
Let `T(n)` be the number of comparisons Quickselect makes to pull out
the k'th smallest element from `n` numbers. Each partition costs `c·n`
comparisons, and it doesn't matter whether the target rank falls in
the left half or the right half, since on average whichever side we recurse
into is about half the size of what we started with:

  T(n) = T(n/2) + c·n   for n > 1
  T(1) = 0

Same recurrence as Q1, so it unrolls the same way:

  T(n) = T(1) + c·n·(1 + 1/2 + 1/4 + ... + 1/2^(k-1)),  where n/2^k = 1
       ≤ 2·c·n

So `T(n) = O(n)` on average, which is the point, since sorting
everything just to grab one element would cost `O(n log n)` for no
real benefit.

Worst case is the same story as before too: if the pivot is always the
smallest or largest element remaining, we don't throw anything away
each round:

  T(n) = T(n-1) + c·n
       = c·n·(n+1)/2  ⇒  O(n²)

## Conclusion
This is really the same trick as Q1, just generalised to any rank `k`
instead of only the middle one. By discarding whichever side of the
partition can't contain the k'th element, we get average `O(n)`
performance without ever sorting the array. Tracking the comparison
counts on random test data backs this up: the numbers scale roughly
linearly with `n`, matching the average-case bound. The `O(n²)` case
only bites on adversarially ordered input, which isn't what's being
tested here.
