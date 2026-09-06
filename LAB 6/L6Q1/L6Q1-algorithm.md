# L6Q1-algorithm

## Aim
Given an unsorted array of `n` integers, work out the worst-case time
complexity of nine common array operations, and validate each with C code.

---

## (i) Maximum element
Walk the array once, keep the biggest value seen so far.

```
procedure FIND-MAX(A[0..n-1])
    mx ← A[0]
    for i ← 1 to n-1
        if A[i] > mx
            mx ← A[i]
        end if
    end for
    return mx
end procedure
```
**Complexity:** O(n).

## (ii) First and second largest
Single pass, but track two running values. When a new element beats
`first`, the old `first` slides down into `second`.

```
procedure FIRST-SECOND-LARGEST(A[0..n-1])
    first ← -infinity
    second ← -infinity
    for i ← 0 to n-1
        if A[i] > first
            second ← first
            first ← A[i]
        else if A[i] > second and A[i] ≠ first
            second ← A[i]
        end if
    end for
    return (first, second)
end procedure
```
**Complexity:** O(n).

## (iii) Mean
Sum every element, divide by `n`.

```
procedure MEAN(A[0..n-1])
    sum ← 0
    for i ← 0 to n-1
        sum ← sum + A[i]
    end for
    return sum / n
end procedure
```
**Complexity:** O(n).

## (iv) Median
Sort the array, then pick the middle element (average the two middle
elements if `n` is even).

```
procedure MEDIAN(A[0..n-1])
    B ← SORT(A)
    if n mod 2 = 0
        return (B[n/2 - 1] + B[n/2]) / 2
    else
        return B[n/2]
    end if
end procedure
```
**Complexity:** O(n log n), dominated by the sort. (A selection algorithm
can find it in O(n) average/worst case, but sorting is the simplest
correct approach and is what's implemented here.)

## (v) Standard deviation
Needs the mean first, then a second pass to sum squared differences from
the mean, then a square root.

```
procedure STD-DEV(A[0..n-1], mean)
    sum ← 0
    for i ← 0 to n-1
        sum ← sum + (A[i] - mean)^2
    end for
    return sqrt(sum / n)
end procedure
```
**Complexity:** O(n).

## (vi) Mode
Sort the array so equal values sit next to each other, then scan once
counting run lengths, keeping the longest run's value.

```
procedure MODE(A[0..n-1])
    B ← SORT(A)
    mode ← B[0]
    bestCount ← 1
    curCount ← 1
    for i ← 1 to n-1
        if B[i] = B[i-1]
            curCount ← curCount + 1
        else
            curCount ← 1
        end if
        if curCount > bestCount
            bestCount ← curCount
            mode ← B[i]
        end if
    end for
    return mode
end procedure
```
**Complexity:** O(n log n) for this sort-based approach. (A hash-table
count gives O(n) average case instead, at the cost of extra memory and
no worst-case guarantee.)

## (vii) Removing duplicates
Sort the array, then walk it once and only keep an element if it differs
from the last one kept.

```
procedure REMOVE-DUPLICATES(A[0..n-1])
    B ← SORT(A)
    k ← 1
    for i ← 1 to n-1
        if B[i] ≠ B[k-1]
            B[k] ← B[i]
            k ← k + 1
        end if
    end for
    return B[0..k-1]
end procedure
```
**Complexity:** O(n log n) (sort dominates; the scan itself is O(n)).

## (viii) Reversing the array
Two pointers, one at each end, swap and step inward until they cross.

```
procedure REVERSE(A[0..n-1])
    l ← 0
    r ← n-1
    while l < r
        swap A[l], A[r]
        l ← l + 1
        r ← r - 1
    end while
end procedure
```
**Complexity:** O(n).

## (ix) Partition around a random pivot (elements >= pivot first, elements < pivot after)
Mirror image of a normal Lomuto partition: pick a random index as pivot,
swap it to the end, do a single pass keeping a `store` pointer, then
swap the pivot into its final spot.

```
procedure PARTITION-GE-PIVOT(A[0..n-1])
    pivotIndex ← RANDOM(0, n-1)
    pivot ← A[pivotIndex]
    swap A[pivotIndex], A[n-1]

    store ← 0
    for i ← 0 to n-2
        if A[i] ≥ pivot
            swap A[i], A[store]
            store ← store + 1
        end if
    end for
    swap A[store], A[n-1]
    return store
end procedure
```
**Complexity:** O(n).

---

## Summary table

| Operation                          | Worst-case complexity |
|-------------------------------------|------------------------|
| Maximum element                     | O(n)                  |
| First & second largest               | O(n)                  |
| Mean                                 | O(n)                  |
| Median                               | O(n log n)            |
| Standard deviation                   | O(n)                  |
| Mode                                 | O(n log n)            |
| Remove duplicates                    | O(n log n)            |
| Reverse                              | O(n)                  |
| Partition around random pivot        | O(n)                  |
