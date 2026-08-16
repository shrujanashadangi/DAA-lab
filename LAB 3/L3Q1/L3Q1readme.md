# Q1 - Binary Search vs Ternary Search

## Files
- `L3Q1.c` - the program
- `L3Q1-algorithm.md` - pseudocode for both search methods
- `L3Q1readme.md` - this file
- `L3Q1.PNG` - graph of comparisons used by binary vs ternary search against `n`

## Mathematical Calculation of Time Complexity

### Binary Search
Recurrence (one comparison to check equality, one to check direction):

  T(n) = T(n/2) + 2,  T(1) = O(1)

Unrolling: T(n) = T(n/2) + 2 = T(n/4) + 4 = ... = T(n/2^k) + 2k
This bottoms out at n/2^k = 1, i.e. k = log₂ n, giving:

  T(n) = O(1) + 2·log₂ n = Θ(log n)

### Ternary Search
Recurrence (two equality checks, two range checks):

  T(n) = T(n/3) + 4,  T(1) = O(1)

Unrolling similarly with k = log₃ n:

  T(n) = O(1) + 4·log₃ n = Θ(log n)

Converting to base 2 for comparison: 4·log₃ n = 4·(log₂ n / log₂ 3) ≈ 2.52·log₂ n

### Comparison
  T_binary(n)  ≈ 2.00 · log₂ n
  T_ternary(n) ≈ 2.52 · log₂ n

Since 2.00 < 2.52, binary search does asymptotically fewer comparisons than
ternary search — even though ternary needs fewer *iterations*
(`log₃ n ≈ 0.631·log₂ n` vs `log₂ n`), each of its iterations costs more
comparisons (up to 4 vs up to 2), and that extra per-iteration cost
outweighs the saving in iteration count.

## Conclusion
Binary search is the better choice for searching a sorted array. Although
ternary search performs fewer *iterations* (`log₃ n` vs `log₂ n`), each of
its iterations requires more element comparisons, so its total comparison
count is asymptotically and, on average, empirically higher than binary
search's. This is also why binary search — not ternary or higher-order
search — is the standard choice in practice: increasing the number of
partitions per step reduces the number of steps but increases the
per-step comparison cost by more than it saves.