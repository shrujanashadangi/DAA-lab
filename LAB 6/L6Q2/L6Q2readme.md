# Q2 - 2D square matrix operations and their complexities

## Files
- `L6Q2.c` - the program
- `L6Q2-algorithm.md` - step-by-step description of each operation
- `L6Q2readme.md` - this file

## What the program does
Takes two `n x n` matrices A and B, then runs all seven operations asked
for in the question: addition and multiplication combine A and B, while
the zero-matrix check, symmetry check, determinant, in-place transpose,
and dominant eigenvalue/eigenvector are single-matrix operations, so
they're run once for A and once for B.

## Input representation
Matrices are stored as a flat `int *` array of size `n*n`, indexed as
`m[i*n + j]` for row `i`, column `j`. This avoids the extra allocation
and pointer indirection of an `int **` array of row pointers, and still
makes in-place transpose straightforward (just swap `m[i*n+j]` with
`m[j*n+i]`).

## A note on eigenvalues
Six of the seven operations have exact, guaranteed-worst-case
algorithms. Eigenvalues don't - for matrices of size 5 and above there is
no general closed-form formula (a real mathematical limit, not an
implementation shortcut), so this program uses power iteration, a
numerical method that converges to the single largest-magnitude
eigenvalue and its eigenvector rather than computing all of them exactly.

## Conclusion
Most matrix operations here land at O(n²) (touching every cell a
constant number of times) or O(n³) (anything that needs a dot product or
elimination step per cell). The determinant, done via Gaussian
elimination instead of cofactor expansion, is the clearest example of
turning an unusable O(n!) approach into a practical O(n³) one. Tested on
a symmetric 3x3 matrix A and a zero matrix B, the program correctly
identified A's symmetry and computed its determinant as 4, correctly
flagged B as a zero matrix with determinant 0, and converged to the
known dominant eigenvalue for both.
