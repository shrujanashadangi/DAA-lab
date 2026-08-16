# L3Q4-algorithm

## Aim
Multiply two `n × n` square matrices `A` and `B` (`n` a power of 2) using
Strassen's divide-and-conquer method, which uses 7 recursive multiplications
of `n/2 × n/2` sub-matrices instead of the naive 8.

---

## Algorithm — `strassen(A, B, n)`
1. Start.
2. If `n = 1`, the product of the two `1 × 1` matrices is simply
   `A[0][0] * B[0][0]` — return it.
3. Otherwise, partition `A` and `B` each into four `n/2 × n/2` quadrants:

     A = | A11 A12 |    B = | B11 B12 |
         | A21 A22 |        | B21 B22 |

4. Compute 7 products, each via a recursive call to `strassen` on
   `n/2 × n/2` matrices:

     M1 = A11 · (B12 - B22)
     M2 = (A11 + A12) · B22
     M3 = (A21 + A22) · B11
     M4 = A22 · (B21 - B11)
     M5 = (A11 + A22) · (B11 + B22)
     M6 = (A12 - A22) · (B21 + B22)
     M7 = (A11 - A21) · (B11 + B12)

5. Combine the 7 products into the four quadrants of the result `C`:

     C11 = M5 + M4 - M2 + M6
     C12 = M1 + M2
     C21 = M3 + M4
     C22 = M5 + M1 - M3 - M7

6. Assemble `C11, C12, C21, C22` into the full `n × n` result matrix `C`
   and return it.
7. Stop.

### Time Complexity
Recurrence: `T(n) = 7·T(n/2) + O(n²)` ⇒ `T(n) = Θ(n^log₂7) ≈ Θ(n^2.807)` — asymptotically better than
naive multiplication's `Θ(n³)`.
