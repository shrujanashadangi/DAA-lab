# L3Q5-algorithm

## Aim
Multiply two `n × n` matrices `A` and `B` (`n = 2^k`) that both have the
recursive block-symmetric pattern

  M = | M1 M2 |
      | M2 M1 |

(with each block itself following the same pattern down to single elements),
using an `O(n²)` divide-and-conquer algorithm.

---

## Deriving the O(n²) approach
Because `A` and `B` both have the form above, their product also has the
same block form, `A·B = [[C1,C2],[C2,C1]]`, with only two distinct blocks:

  C1 = A1B1 + A2B2      C2 = A1B2 + A2B1

Computing these directly still needs 4 sub-multiplications. A
Karatsuba-style identity reduces this to 2:

  P = (A1+A2)(B1+B2) = A1B1+A1B2+A2B1+A2B2
  Q = (A1-A2)(B1-B2) = A1B1-A1B2-A2B1+A2B2
  ⇒ C1 = (P+Q)/2 ,  C2 = (P-Q)/2

Since sums/differences of block-symmetric matrices are themselves
block-symmetric, `P` and `Q` can be computed by the *same* algorithm
recursively on `n/2 × n/2` matrices.

## Algorithm — `mul(A, B, n)`
1. Start.
2. If `n = 1`, return the single-element product `A[0][0] * B[0][0]`.
3. Otherwise, extract `A1` (top-left `n/2` block of `A`) and `A2` (top-right
   `n/2` block of `A`) — the pattern guarantees the bottom-left/bottom-right
   blocks are just copies of these, so they never need to be read
   separately. Likewise extract `B1`, `B2` from `B`.
4. Compute `Pa = A1 + A2`, `Qa = A1 - A2`, `Pb = B1 + B2`, `Qb = B1 - B2`.
5. Recursively compute `Pc = mul(Pa, Pb, n/2)` and `Qc = mul(Qa, Qb, n/2)`.
6. Compute `C1 = (Pc + Qc) / 2` and `C2 = (Pc - Qc) / 2`.
7. Assemble the result as `[[C1, C2], [C2, C1]]` and return it.
8. Stop.

### Time Complexity
Recurrence: `T(n) = 2·T(n/2) + O(n²)` ⇒ `T(n) = Θ(n²)`— asymptotically better than
both naive `Θ(n³)` and Strassen's `Θ(n^2.807)`.
