# L7Q5 - Hitting a moving target

## Files
- `L7Q5.c` - the program
- `L7Q5-algorithm.md` - pseudocode matching the code
- `L7Q5-readme.md` - readme (this file)

## Does a guaranteed strategy exist?
Yes, for every n >= 2. The shooter never needs to see the target:
sweeping through the middle spots once in each direction is enough to
eventually line up with it, because the target's position and the
number of moves it has made always share the same parity.

## Time complexity
Building the sequence: the first loop runs from 2 to n-1, which is
n-2 steps, and the second loop runs from n-1 down to 2, another n-2
steps. Adding these gives 2(n-2) steps total, so building the sequence
is O(n) time and O(n) space to store it.

The brute-force check tries n starting spots, times 2 possible
starting directions, and for each of those it walks through all
O(n) shots in the sequence. That gives n * 2 * O(n) = O(n^2) time for
the check.

## Conclusion
Run for n = 2 through 10, and spot-checked at larger values, the
brute-force check always confirms the target gets caught, including
the n = 2 case, which needs the "shoot the same spot twice" trick
rather than the general sweep.
