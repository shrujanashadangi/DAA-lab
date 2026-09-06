# L6Q3-algorithm

## Aim
Compute the convolution `C = A * B` of two vectors A (length m) and B
(length n, n >= m), where

  C[k] = sum over j=0..m-1 of A[j] * B[k-j]

in O(n log n) time using divide and conquer, instead of the naive
O(n*m).

---

## Why the naive way is slow
Directly computing every `C[k]` from the formula above costs O(m) work
per output value, and there are `m+n-1` output values, so the naive
approach is O(n*m).

## The divide and conquer idea: convolution via FFT
Convolution in the "normal" domain corresponds to plain multiplication
in the frequency domain. So the plan is: pad both vectors to the same
power-of-two length, transform both with the FFT, multiply pointwise,
then transform the product back with the inverse FFT.

```
procedure FFT(a[0..n-1], invert)
    if n = 1
        return a
    end if

    even ← FFT(a[0], a[2], a[4], ..., invert)
    odd  ← FFT(a[1], a[3], a[5], ..., invert)

    for k ← 0 to n/2 - 1
        sign ← invert ? +1 : -1
        angle ← sign * 2π * k / n
        w ← cos(angle) + i * sin(angle)
        t ← w * odd[k]
        a[k]       ← even[k] + t
        a[k + n/2] ← even[k] - t
    end for

    return a
end procedure

procedure CONVOLVE(A[0..m-1], B[0..n-1])
    size ← next power of 2 that is ≥ m + n - 1
    pad A and B with zeros up to length size

    FA ← FFT(A, invert = false)
    FB ← FFT(B, invert = false)

    for i ← 0 to size-1
        FA[i] ← FA[i] * FB[i]        // pointwise multiply
    end for

    C ← FFT(FA, invert = true)
    for i ← 0 to size-1
        C[i] ← C[i] / size
    end for

    return C[0 .. m+n-2]
end procedure
```

## The FFT itself is the divide and conquer part
`FFT` splits the input into its even-indexed and odd-indexed halves,
recursively transforms each half, then combines the two half-results
using `n/2` "butterfly" combine steps involving complex roots of unity.
This is the classic Cooley-Tukey recursive structure:

  T(n) = 2*T(n/2) + O(n)

which solves to O(n log n) by the master theorem - the same shape as
merge sort.

## Padding requirement
The FFT needs its input length to be a power of two, so both vectors are
zero-padded up to `size = nextPowerOf2(m + n - 1)`. Padding with zeros
doesn't change the values being convolved, it just gives the recursion
clean halves to split.

### Time Complexity
- FFT of a vector of length `size`: O(size log size)
- Two forward FFTs + one inverse FFT + one pointwise multiply:
  O(size log size)
- Since `size` is at most about `2*(m+n)`, this is **O(n log n)**
  overall (n >= m), meeting the bound required by the question.
