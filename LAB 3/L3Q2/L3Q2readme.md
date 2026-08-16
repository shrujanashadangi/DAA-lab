# Q2 - Search the Defective (Lighter) Coin

## Files
- `L3Q2.c` - the program
- `L3Q2-algorithm.md` - divide-and-conquer pseudocode
- `L3Q2readme.md` - this file
- `L3Q2.PNG` - graph of weighings used against `n`

## Mathematical Calculation of Time Complexity
Each weighing splits the current candidate set of size `n` into two equal
groups of size `⌊n/2⌋`, and determines which group (if any) contains the
defective coin — the other group is thereby proven genuine and becomes a
free reference for later comparisons. This gives the recurrence:

  T(n) = T(⌈n/2⌉) + 1,  T(1) = O(1)

Unrolling:

  T(n) = T(n/2) + 1 = T(n/4) + 2 = ... = T(n/2^k) + k

The recursion bottoms out (`n/2^k = 1`) after `k = ⌈log₂ n⌉` steps, so:

  T(n) = ⌈log₂ n⌉ + c

where `c` is at most 2 — one extra weighing may be needed when a split is
odd (to test the leftover coin), and one extra weighing may be needed at the
final base case to confirm the last suspect coin against a genuine
reference.

## Conclusion
The divide-and-conquer weighing strategy locates the single lighter coin (or
correctly proves none exists) using only `O(log₂ n)` weighings, because each
weighing simultaneously (a) halves the search space and (b) certifies an
entire group of coins as genuine reference material for later steps — a
result no linear scan could match. The implementation's measured weighing
counts stay within `⌊log₂ n⌋ + 2` across all tested `n`, confirming the
`log₂ n + c` bound required by the question.