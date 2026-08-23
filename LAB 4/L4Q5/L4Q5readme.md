# Q5 - Merge overlapping intervals

## Files
- `L4Q5.c` - the program
- `L4Q5-algorithm.md` - pseudocode matching the code

## Approach
We sort the intervals by their starting value. Then we walk through them one by one, keeping a current interval in hand. If the next interval starts before or right where the current one ends, they overlap, so we stretch the current interval to also cover the next one. If not, we close off the current interval and start fresh with the next one.

## Time complexity
Let n be the number of intervals.

Sorting the intervals by start value: O(n log n)

Sweeping through the sorted intervals: each interval is looked at once and either merged into the current interval or closed off.
Cost = O(n)

Total time,
T(n) = O(n log n) + O(n) = O(n log n)

## Conclusion
The question asks for a worst case O(n log n) algorithm, and once the intervals are sorted by start, any two intervals that overlap are guaranteed to sit next to each other, so a single pass after sorting is all that's needed.
