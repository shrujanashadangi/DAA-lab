# Q3 - Merging k sorted arrays: sequential vs pairwise

## Files
- `L2Q3.c` - the program
- `ALGORITHM.md` - pseudocode matching the code
- `L2Q3.PNG` -  chart for the graph


## Time complexity

### Method 1: sequential merging

Each merge combines the current pile with the next array of size n. The
pile's size grows by n each time, so the cost of each successive merge
grows too:
```
merge 1:  |arrays[0]| + |arrays[1]| = n + n     = 2n
merge 2:  (2n) + n                              = 3n
merge 3:  (3n) + n                              = 4n
...
merge k-1: ((k-1)n) + n                         = kn
```
Total:
```
T(n,k) = 2n + 3n + 4n + ... + kn
       = n * (2 + 3 + ... + k)
       = n * ( (1+2+...+k) - 1 )
       = n * ( k(k+1)/2 - 1 )
```
Expanding the bracket, the k² term dominates as k grows:
```
T(n,k) = (n/2)k² + (n/2)k - n  =  O(nk²)
```

### Method 2: pairwise (tournament) merging

Each full pass merges every array in the current set exactly once. No
matter how many arrays remain in a given pass, they always add up to
the full k*n elements total, so **every pass costs O(kn)**, regardless
of which pass it is.

The number of arrays halves each pass (k → k/2 → k/4 → ... → 1), so the
number of passes is:
```
number of passes = log₂ k
```
Total:
```
T(n,k) = O(kn) * log₂ k = O(nk log k)
```

### Comparing them

Take the ratio of the two formulas:
```
nk² / (nk log k) = k / log k
```
As k grows, k/log k grows without bound - meaning method 1's cost grows
strictly faster than method 2's, by a widening margin, not just a fixed
constant-factor gap. At k=512: method 1 ≈ n*(512²/2) work, method 2 ≈
n*512*9 work - a ratio of roughly 28:1 in favor of pairwise merging at
that point, and it keeps growing as k increases further.

**Method 1 is O(nk²), method 2 is O(nk log k) - genuinely different
growth classes in k**, not just different constants (unlike Q2, where
both sorts landed in the same O(n log n) class).

## Comparison

| | Method 1 | Method 2 |
|---|---|---|
| Growth in k | quadratic | near-linear |
| Measured (k=512, n=50) | 24.02 ms | 1.41 ms |

Only k is charted in the xlsx, not n - both formulas are linear in n
(clear from the math above), k is where the two methods actually diverge.

## Conclusion

Sequential merging is fine for a small number of arrays but gets
expensive fast as k grows. Pairwise merging avoids this by only ever
combining similarly-sized piles - same divide-and-conquer idea behind
regular merge sort, applied to k pre-sorted chunks instead of individual
elements.