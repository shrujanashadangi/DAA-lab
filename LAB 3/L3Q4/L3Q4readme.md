# Q4 - Matrix Multiplication using Strassen's Method

## Files
- `L3Q4.c` - the program
- `L3Q4-algorithm.md` - pseudocode
- `L3Q4readme.md` - this file
- `L3Q4.PNG` - graph comparing Strassen's method vs naive multiplication against `n`

## Mathematical Calculation of Time Complexity
Strassen's method partitions each `n × n` matrix into four `n/2 × n/2`
quadrants and computes the product using only **7** sub-matrix
multiplications instead of the 8 a naive block-multiplication would need,
at the cost of a constant number of `O(n²)` additions/subtractions to
prepare operands and recombine results. This gives the recurrence:

  T(n) = 7·T(n/2) + O(n²)

By the Master Theorem, with `a = 7`, `b = 2`, `f(n) = O(n²)`:

  log_b(a) = log₂ 7 ≈ 2.807

Since `f(n) = O(n²)` and the exponent `2 < log₂ 7 ≈ 2.807`, this falls into
**Case 1** of the Master Theorem:

  T(n) = Θ(n^log₂7) ≈ Θ(n^2.807)

For comparison, naive matrix multiplication follows `T(n) = 8·T(n/2) + O(n²)`
(8 sub-multiplications, no reduction trick), which by the same theorem
(`log₂ 8 = 3`, Case 1) gives `T(n) = Θ(n³)`. So Strassen's method is
asymptotically faster than naive multiplication.

## Conclusion
The implementation correctly follows Strassen's 7-multiplication formulas
and produces results identical to standard matrix multiplication, while
running in `Θ(n^2.807)` time instead of `Θ(n³)` — a meaningful asymptotic
improvement, though in practice Strassen's method is only worthwhile for
sufficiently large `n` because of its larger constant factor (extra
matrix additions/subtractions and recursive-call overhead) compared to the
simple triple-loop method.