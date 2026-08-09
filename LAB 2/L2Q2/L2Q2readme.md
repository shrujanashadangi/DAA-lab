# Q2 - Merge sort vs modified (3-way) merge sort

## Files
- `L2Q2.c` - the program
- `ALGORITHM.md` - pseudocode matching the code
- `L2Q2.PNG` - chart for the graph


## Time complexity

### Regular merge sort (2-way)

Recurrence: split into 2 halves of size n/2, merge back together in O(n).
```
T(n) = 2T(n/2) + cn
```

Recursion tree, cost level by level:
```
level 0:  1 problem,   size n     -> cost cn
level 1:  2 problems,  size n/2   -> cost 2*(cn/2) = cn
level 2:  4 problems,  size n/4   -> cost 4*(cn/4) = cn
...
level i:  2^i problems, size n/2^i -> cost 2^i * c(n/2^i) = cn
```
Every level costs cn, and the tree has depth log₂ n. Total:
```
T(n) = cn * log₂ n = O(n log n)
```

### Modified merge sort (3-way)

Recurrence: split into 3 thirds of size n/3, merge 3 runs together in O(n).
```
T(n) = 3T(n/3) + cn
```

Same idea, different branching factor:
```
level i:  3^i problems, size n/3^i -> cost 3^i * c(n/3^i) = cn
```
Every level still costs cn, but the tree only reaches depth log₃ n.
Total:
```
T(n) = cn * log₃ n = O(n log n)
```

### Comparing them

`log₃ n = log₂ n / log₂ 3`, and log₂ 3 ≈ 1.585, so:
```
log₃ n ≈ 0.631 * log₂ n
```
The 3-way tree has about 37% fewer levels. That's the direct source of
the measured speed-up. It's partly offset by a pricier merge step per
level (finding the min of 3 values takes 2 comparisons vs 1 for the min
of 2), but the level reduction wins out, matching the ~13% speed-up seen
in testing. Both stay **O(n log n)** either way - a log with a different
base is only a constant factor apart from any other log, so the growth
class doesn't change, only the constant does.

## Comparison

| | Regular (2-way) | Modified (3-way) |
|---|---|---|
| Growth | O(n log₂ n) | O(n log₃ n) |
| Measured at n=256000 | 59.34 ms | 51.55 ms |

## Conclusion

Same complexity class, both O(n log n). 3-way is consistently faster by
a small constant factor (~10-15% in testing) because it has fewer
recursion levels - not a fundamentally different algorithm, just a
better-tuned one.