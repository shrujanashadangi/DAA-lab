# Q3 - Quicksort on N Random Elements Stored in a File

## Files
- `L5Q3.c` - the program
- `L5Q3-algorithm.md` - pseudocode
- `L5Q3readme.md` - this file

## Mathematical Calculation of Time Complexity
Let `T(n)` be the number of comparisons Quicksort makes while sorting
the `n` numbers read back from the file. Each partition pass costs
`c·n` comparisons, and on random data the pivot tends to split the
array into two roughly even halves:

  T(n) = 2·T(n/2) + c·n   for n > 1
  T(1) = 0

To solve it, guess `T(n) = c·n·log2(n)` and check it actually satisfies
the recurrence:

  2·T(n/2) + c·n = 2·c·(n/2)·log2(n/2) + c·n
                 = c·n·(log2(n) - 1) + c·n
                 = c·n·log2(n) - c·n + c·n
                 = c·n·log2(n)

That matches the guess exactly, so:

  T(n) = Θ(n log n)   on random / average-case input

If the file happened to contain already-sorted (or reverse-sorted)
data and the pivot is always the last element, every partition peels
off just a single element instead of splitting evenly:

  T(n) = T(n-1) + c·n
       = c·n·(n+1)/2  ⇒  O(n²)

## Conclusion
Since the numbers are freshly randomised every run before being
written to `input.txt`, what Quicksort actually ends up sorting is
random data, exactly the scenario where its `Θ(n log n)` average case
applies. Tracking the observed comparisons as `n` increases shows them
following the `n log n` curve. The `O(n²)` worst case is a known
weakness of Quicksort but would only show up if the input file
happened to already be sorted, which it isn't here.
