# L3Q3-algorithm

## Aim
Find the minimum and maximum elements of an array of `n` elements using
divide-and-conquer, such that the total number of comparisons is bounded by
`3n/2`.

---

## Algorithm — `getMinMax(a, l, r)`
Returns the `(min, max)` pair for the sub-array `a[l..r]`.

1. Start.
2. If `l = r` (a single element), return `a[l]` as both the minimum and the
   maximum — no comparison needed.
3. If `r = l + 1` (two elements), compare `a[l]` with `a[r]` directly
   (1 comparison) to determine which is the minimum and which is the
   maximum.
4. Otherwise, split the sub-array at `mid = l + (r - l) / 2`, and
   recursively find `(min1, max1) = getMinMax(a, l, mid)` and
   `(min2, max2) = getMinMax(a, mid+1, r)`.
5. Compare `min1` with `min2` (1 comparison) to get the overall minimum,
   and compare `max1` with `max2` (1 comparison) to get the overall
   maximum.
6. Return the combined minimum and maximum.
7. Stop.

### Time Complexity
Comparisons: `C(n) ≈ 3n/2` (exactly `3n/2 - 2` for `n = 2^k`), i.e. **O(n)**. This beats the naive approach of
finding min and max separately (each costing `n - 1` comparisons, `2n - 2`
total).
