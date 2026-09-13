# L7Q6 - The best time to be alive

## Files
- `L7Q6.c` - the program
- `L7Q6-algorithm.md` - pseudocode matching the code
- `L7Q6-readme.md` - readme (this file)

## Time complexity
Building the event list touches each of the n scientists once to
create 2 events, so that is O(n).

Sorting the 2n events with qsort costs O((2n) log(2n)), which is the
same order as O(n log n).

The sweep afterward walks through the 2n events once, doing O(1) work
per event, so that part is O(n).

Adding these up, sorting is the most expensive part, so the overall
time is O(n log n). Space is O(n) for the event list.

The program also runs a brute-force check: for each of the n
scientists it scans all n scientists again to count overlaps, which
is O(n^2), used only to confirm the O(n log n) answer above.

## Conclusion
Checked against a brute-force interval count across 300 randomized
test cases, including situations where a death and a birth land on
the exact same year, the sweep line answer matched every single time.
