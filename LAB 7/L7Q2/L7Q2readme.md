# L7Q2 - Super egg testing experiment

## Files
- `L7Q2.c` - the program
- `L7Q2-algorithm.md` - pseudocode matching the code
- `L7Q2-readme.md` - readme (this file)

## Time complexity
The table dp has (E+1) rows and (F+1) columns, so it uses O(E * F)
space.

Filling it costs: the outer loop over i runs E-1 times (from 2 to E),
the loop over j inside it runs F-1 times (from 2 to F), and for each
(i, j) pair the innermost loop over x runs up to j times, which is at
most F. Multiplying these three bounds together gives

    (E) * (F) * (F) = O(E * F^2)

which is the total number of basic operations, so the running time is
O(E * F^2).

## Conclusion
For 2 eggs and 100 floors the program gives 14, which is the well
known answer to that version of the puzzle. Dropping down to 1 egg
correctly falls back to a plain linear search through all F floors,
which is a good sanity check that the recurrence is behaving.
