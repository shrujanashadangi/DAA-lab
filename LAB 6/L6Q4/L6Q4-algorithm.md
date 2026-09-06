# L6Q4-algorithm

## Aim
Given a permutation `p` of `1..n`, sort it using only `reverse(p, i, j)`
(reverses the elements between positions `i` and `j`).
- Part 1: show O(n) reversals always suffice.
- Part 2: if `reverse(p, i, j)` costs `|j - i| + 1`, design an algorithm
  that sorts in O(n log^2 n) total cost.

---

## Part 1: O(n) reversals always suffice

**Claim:** any permutation of `1..n` can be sorted in at most `n - 1`
reversals.

**Idea (like selection sort):** for each position `i`, the value that
belongs there is `i + 1`. Find where that value currently sits, then
reverse the range from `i` up to that spot - this brings the correct
value straight to position `i` without disturbing anything already
placed before it.

```
procedure SORT-BY-SELECTION-REVERSAL(P[0..n-1])
    for i ← 0 to n-2
        j ← index of value (i+1) in P[i..n-1]
        REVERSE(P, i, j)
    end for
end procedure
```

**Proof:** each loop iteration fixes exactly one position and never
touches a position before `i`, so after `n-1` iterations positions
`0..n-2` are correct, and the last slot must hold `n` by elimination.
That's at most `n-1` reversal calls, so the reversal **count** is O(n).
QED. (This doesn't yet worry about the *cost* of each reversal - that's
Part 2.)

---

## Part 2: O(n log^2 n) cost algorithm

The selection-sort approach above can need a full-length reversal at
almost every step, giving O(n²) total cost in the worst case. A
merge-sort style approach does much better: split the array in half,
recursively sort each half, then merge in place using only reversals.

```
procedure REVERSE(P, i, j)
    while i < j
        swap P[i], P[j]
        i ← i + 1
        j ← j - 1
    end while
end procedure

procedure ROTATE(P, l, mid, r)
    // moves block P[mid..r] in front of block P[l..mid-1]
    REVERSE(P, l, mid - 1)
    REVERSE(P, mid, r)
    REVERSE(P, l, r)
end procedure

procedure LOWER-BOUND(P, lo, hi, key)
    // first index in [lo, hi) with P[index] ≥ key
    while lo < hi
        mid ← lo + (hi - lo) / 2
        if P[mid] < key
            lo ← mid + 1
        else
            hi ← mid
        end if
    end while
    return lo
end procedure

procedure MERGE-BY-ROTATION(P, l, mid, r)
    i ← l
    j ← mid + 1
    while i < j and j ≤ r
        if P[i] ≤ P[j]
            i ← i + 1
        else
            pos ← LOWER-BOUND(P, j, r + 1, P[i])
            ROTATE(P, i, j, pos - 1)
            i ← i + (pos - j)
            j ← pos
        end if
    end while
end procedure

procedure SORT-BY-REVERSAL(P, l, r)
    if l ≥ r
        return
    end if
    mid ← l + (r - l) / 2
    SORT-BY-REVERSAL(P, l, mid)
    SORT-BY-REVERSAL(P, mid + 1, r)
    MERGE-BY-ROTATION(P, l, mid, r)
end procedure
```

### Why the merge works
Walking pointers `i` (left run) and `j` (right run): if `P[i] ≤ P[j]`
that element is already in place, so `i` advances. Otherwise a whole
block of right-run elements is smaller than `P[i]` - binary search finds
exactly how many, and a single rotate moves that whole block in front of
`P[i]` in one shot instead of shuffling one element at a time.

### Why the cost works out to O(n log^2 n)
- Merge sort has O(log n) levels, and every level merges runs whose
  sizes add up to `n` in total.
- At each level, each merge step does a handful of binary searches
  (O(log n) each) and a handful of rotations, and each rotation's cost
  is proportional to the size of the block it moves. Batching multiple
  out-of-place elements into a single rotation keeps the per-level cost
  to about O(n log n) - an extra log factor over a plain linear merge,
  coming from the binary-search-guided rotations.
- Multiplying by the O(log n) levels of the recursion gives a total cost
  of **O(n log^2 n)**, matching the bound the question asks for.

### Correctness
Every reversal is a valid, reversible rearrangement, so the array always
stays a permutation of the original. The merge step only ever moves an
element past values it's genuinely smaller or larger than (verified via
direct comparison and binary search over already-sorted runs), so the
merged range ends up fully sorted. By induction (base case: single
elements are trivially sorted), the whole array ends up sorted once the
top-level merge finishes.
