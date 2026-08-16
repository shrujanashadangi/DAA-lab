# L3Q1-algorithm

## Aim
Search for an element `x` in a sorted array of `n` elements using both Binary
Search and Ternary Search, counting the comparisons used by each.

---

## 1. Binary Search

### Algorithm
1. Start.
2. Set `lo = 0` and `hi = n - 1`.
3. While `lo <= hi`, repeat steps 4-5.
4. Compute the middle index `m = lo + (hi - lo) / 2`, and compare `a[m]`
   with `x`. If they are equal, `x` has been found at index `m` — stop.
5. Otherwise, compare `a[m]` with `x` again: if `a[m]` is smaller than `x`,
   discard the left half by setting `lo = m + 1`; otherwise discard the
   right half by setting `hi = m - 1`.
6. If the loop ends without finding `x`, return -1 to indicate it is not
   present.
7. Stop.

### Time Complexity
Best case: O(1) | Worst / Average case: O(log₂ n)

---

## 2. Ternary Search

### Algorithm
1. Start.
2. Set `lo = 0` and `hi = n - 1`.
3. While `lo <= hi`, repeat steps 4-6.
4. Compute two dividers, `m1 = lo + (hi - lo) / 3` and
   `m2 = hi - (hi - lo) / 3`, splitting the current range into three
   near-equal parts.
5. Compare `a[m1]` with `x`; if equal, return `m1`. Otherwise compare
   `a[m2]` with `x`; if equal, return `m2`.
6. Otherwise, decide which third to continue searching: if `x` is smaller
   than `a[m1]`, continue in the first third (`hi = m1 - 1`); if `x` is
   larger than `a[m2]`, continue in the third third (`lo = m2 + 1`);
   otherwise continue in the middle third (`lo = m1 + 1`, `hi = m2 - 1`).
7. If the loop ends without finding `x`, return -1.
8. Stop.

### Time Complexity
Best case: O(1) | Worst / Average case: O(log₃ n)
