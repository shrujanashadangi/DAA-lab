# Q3 - Convolution operation on vectors of size n

## Files
- `L6Q3.c` - the program
- `L6Q3-algorithm.md` - explanation of the FFT-based divide and conquer approach
- `L6Q3readme.md` - this file

## What the program does
Takes vector A (length m) and vector B (length n, with n >= m), and
computes their convolution C (length m+n-1) by transforming both into
the frequency domain with an FFT, multiplying them there, and
transforming the product back.

## Input representation
Vectors are stored as `double` arrays (not `int`), since the FFT works
in the complex domain and needs floating point arithmetic even if the
final convolution values happen to be whole numbers.

## Mathematical Calculation of Time Complexity
Let `T(n)` be the time to run the FFT on a vector of length `n`
(assumed a power of two):

  T(1) = O(1)
  T(n) = 2*T(n/2) + O(n)

The `O(n)` term is the work done combining the two half-transforms (one
butterfly operation per output index). By the master theorem this
recurrence solves to:

  T(n) = O(n log n)

Since convolution needs two forward FFTs, one pointwise multiply
(O(n)), and one inverse FFT, the total stays O(n log n). This is
strictly better than the O(n*m) naive approach for any vectors large
enough to matter.

## Conclusion
Padding both input vectors up to the next power of two lets the FFT's
divide-and-conquer split work cleanly, and turns an O(n*m) sliding-sum
problem into an O(n log n) transform-multiply-untransform problem. The
implementation was checked against a small hand-computed example
(A = [1, 2, 3], B = [0, 1, 0.5]) and produced the exact expected
convolution [0, 1, 2.5, 4, 1.5].
