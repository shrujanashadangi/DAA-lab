# Q3 - Min and Max using Divide and Conquer

## Files
- `L3Q3.c` - the program
- `L3Q3-algorithm.md` - pseudocode
- `L3Q3readme.md` - this file
- `L3Q3.PNG` - graph of comparisons used against `n`, plotted against the `3n/2` bound

## Mathematical Calculation of Time Complexity
Let `C(n)` be the number of comparisons for `n` elements:

  C(1) = 0
  C(2) = 1
  C(n) = 2·C(n/2) + 2   for n > 2

Solve by substitution: assume `C(n) = a·n + b`.

  2·C(n/2) + 2 = 2·(a·n/2 + b) + 2 = a·n + 2b + 2

Setting this equal to `a·n + b` gives `b = 2b + 2`, i.e. `b = -2`.
Using the base case `C(2) = 1`: `2a - 2 = 1` ⇒ `a = 3/2`.

Therefore, for `n = 2^k`:

  C(n) = (3/2)·n - 2

which is strictly less than `3n/2` — satisfying the bound required by the
question. Asymptotically, `C(n) = Θ(n)`.

## Conclusion
By solving the two halves independently and combining their results with
only 2 comparisons (rather than treating min and max as two completely
separate O(n) scans, which would cost `2n - 2` comparisons total), this
divide-and-conquer strategy roughly **halves** the number of comparisons
needed compared to the naive method, achieving `3n/2` instead of `2n`. The
implementation was validated to stay within the `3n/2` bound for every
tested input size, and to hit the exact optimal `⌈3n/2⌉ - 2` whenever `n`
is a power of two.