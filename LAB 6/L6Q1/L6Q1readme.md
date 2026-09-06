# Q1 - 1D array operations and their complexities

## Files
- `L6Q1.c` - the program
- `L6Q1-algorithm.md` - step-by-step description of each operation
- `L6Q1readme.md` - this file

## What the program does
Takes `n` unsorted integers as input and runs all nine operations asked
for in the question one after another: max, first & second largest,
mean, median, standard deviation, mode, duplicate removal, reversing the
array, and partitioning it around a randomly chosen pivot so that
everything `>= pivot` ends up before everything `< pivot`.

## Input representation
A plain `int` array read from stdin, size `n` given up front. This is
the natural representation since the questions themselves are phrased in
terms of array indices and comparisons - no extra structure (like a
sorted array or hash map) is assumed going in, since the array is stated
to be unsorted.

## Complexity summary
Most of these operations (max, top-2, mean, std dev, reverse, partition)
only need a constant amount of work per element, so they run in O(n).
Median, mode, and duplicate removal are implemented here using a sort
first, which pushes them to O(n log n) - sorting is the simplest way to
get a correct answer for these, even though faster average-case options
(hashing, selection algorithms) exist.

## Conclusion
Out of the nine operations, six are fundamentally linear scans and three
are bottlenecked by needing the data in sorted order first. The program
was tested on arrays containing duplicate values (to properly exercise
mode and duplicate removal) and confirms all nine operations produce
correct results in a single run over the same input array.
