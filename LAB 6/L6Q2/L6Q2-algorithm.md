# L6Q2-algorithm

## Aim
Given square matrices of size `n x n`, work out the worst-case time
complexity of seven common matrix operations, and validate each with C
code.

---

## (i) Matrix addition
Add corresponding entries.

```
procedure ADD(A, B, n)
    for i ← 0 to n-1
        for j ← 0 to n-1
            C[i][j] ← A[i][j] + B[i][j]
        end for
    end for
    return C
end procedure
```
**Complexity:** O(n²).

## (ii) Matrix multiplication
For every output cell, take the dot product of a row of A and a column
of B.

```
procedure MULTIPLY(A, B, n)
    for i ← 0 to n-1
        for j ← 0 to n-1
            sum ← 0
            for k ← 0 to n-1
                sum ← sum + A[i][k] * B[k][j]
            end for
            C[i][j] ← sum
        end for
    end for
    return C
end procedure
```
**Complexity:** O(n³) for the naive triple-loop method used here.
(Strassen's algorithm reaches roughly O(n^2.81), but that's not what's
implemented.)

## (iii) Zero matrix check
Scan every cell; bail out the moment a non-zero entry is found.

```
procedure IS-ZERO(A, n)
    for i ← 0 to n-1
        for j ← 0 to n-1
            if A[i][j] ≠ 0
                return false
            end if
        end for
    end for
    return true
end procedure
```
**Complexity:** O(n²) worst case.

## (iv) Symmetric check
Only the upper triangle needs checking against the lower triangle.

```
procedure IS-SYMMETRIC(A, n)
    for i ← 0 to n-1
        for j ← i+1 to n-1
            if A[i][j] ≠ A[j][i]
                return false
            end if
        end for
    end for
    return true
end procedure
```
**Complexity:** O(n²).

## (v) Determinant
Cofactor expansion is O(n!), unusable beyond tiny matrices. Instead this
uses Gaussian elimination with partial pivoting to reduce A to
upper-triangular form, then multiplies the diagonal.

```
procedure DETERMINANT(A, n)
    det ← 1
    for i ← 0 to n-1
        pivotRow ← row k in [i, n-1] with largest |A[k][i]|
        if |A[pivotRow][i]| ≈ 0
            return 0
        end if
        if pivotRow ≠ i
            swap rows A[i], A[pivotRow]
            det ← -det
        end if
        det ← det * A[i][i]
        for k ← i+1 to n-1
            factor ← A[k][i] / A[i][i]
            for j ← i to n-1
                A[k][j] ← A[k][j] - factor * A[i][j]
            end for
        end for
    end for
    return det
end procedure
```
**Complexity:** O(n³) - each of the `n` elimination steps clears a
column below the pivot, costing O(n²) per step.

## (vi) Transpose in place
Swap `A[i][j]` with `A[j][i]` for every pair above the diagonal.

```
procedure TRANSPOSE-IN-PLACE(A, n)
    for i ← 0 to n-1
        for j ← i+1 to n-1
            swap A[i][j], A[j][i]
        end for
    end for
end procedure
```
**Complexity:** O(n²), O(1) extra space.

## (vii) Eigenvalue and eigenvector
For `n ≥ 5` there is provably no general algebraic formula that finds
exact eigenvalues in finitely many steps (Abel-Ruffini theorem, since
eigenvalues are roots of the matrix's degree-`n` characteristic
polynomial). So instead of an exact method, this uses **power
iteration**: start with a guess vector, repeatedly multiply by A and
renormalize, and the vector converges toward the eigenvector for the
largest-magnitude eigenvalue.

```
procedure POWER-ITERATION(A, n, iterations)
    x ← vector of 1s, length n
    eigenValue ← 0
    for it ← 1 to iterations
        y ← A * x
        norm ← ||y||
        if norm ≈ 0
            break
        end if
        x ← y / norm
        eigenValue ← norm
    end for
    return (eigenValue, x)
end procedure
```
**Complexity:** O(k n²), where `k` is the number of iterations (each
iteration is one matrix-vector multiply, O(n²)). This only finds the
single dominant eigenvalue/eigenvector - finding all of them typically
uses the QR algorithm, O(n³) per sweep and several sweeps to converge.

---

## Summary table

| Operation                  | Worst-case complexity      |
|------------------------------|-----------------------------|
| Matrix addition               | O(n²)                      |
| Matrix multiplication          | O(n³)                      |
| Zero matrix check              | O(n²)                      |
| Symmetric check                | O(n²)                      |
| Determinant                    | O(n³)                      |
| Transpose in place              | O(n²), O(1) extra space    |
| Dominant eigenvalue/vector       | O(k n²), k = iterations     |
