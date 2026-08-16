# Q5 - Multiply Special-Pattern Square Matrices in O(n²)

## Files
- `L3Q5.c` - the program
- `L3Q5-algorithm.md` - derivation and pseudocode
- `L3Q5readme.md` - this file
- `L3Q5.PNG` - graph comparing this O(n²) method vs Strassen vs naive multiplication against `n`

## Mathematical Calculation of Time Complexity
The algorithm makes 2 recursive calls on `n/2 × n/2` matrices (`Pc = mul(Pa,Pb,n/2)`,
`Qc = mul(Qa,Qb,n/2)`), plus a constant number of `O(n²)` additions/subtractions
to build `Pa, Qa, Pb, Qb` and to combine `Pc, Qc` into `C1, C2`. This gives
the recurrence:

  T(n) = 2·T(n/2) + Θ(n²)

By the Master Theorem, with `a = 2`, `b = 2`, `f(n) = Θ(n²)`:

  log_b(a) = log₂ 2 = 1

Since `f(n) = Θ(n²)` and the exponent `2 > log₂ 2 = 1`, this falls into
**Case 3** of the Master Theorem (with the regularity condition satisfied,
as `f(n) = Θ(n²)` is a polynomial):

  T(n) = Θ(f(n)) = Θ(n²)

This is asymptotically better than both naive multiplication (`Θ(n³)`) and
Strassen's general-purpose method (`Θ(n^2.807)`), and is optimal up to
constant factors since simply reading an `n × n` input already takes
`Ω(n²)` time.

## Conclusion
The special block-symmetric structure of the input matrices is not just
convenient for storage — it can be actively exploited by the
divide-and-conquer strategy: (1) the output inherits the same structure, so
only two block products need to be found, and (2) those two products can be
obtained from only two recursive half-size multiplications via a
Karatsuba-style identity. The result is an `O(n²)` algorithm, i.e. no worse
than the cost of simply writing down the output matrix, and asymptotically
faster than both naive multiplication and Strassen's general algorithm.