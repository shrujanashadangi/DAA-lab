# L7Q1 - Invert the coin-triangle

## Files
- `L7Q1.c` - the program
- `L7Q1-algorithm.md` - pseudocode matching the code
- `L7Q1-readme.md` - readme (this file)

## Formula
For an n-row triangle, the minimum number of coins that need to move
works out to floor(n(n+1)/6).

## Time complexity
The outer loop tries dy from 0 to n, and dx2 over 2 fixed values, so
that is (n+1) * 2 = O(n) candidate shifts in total.

For each candidate shift, `overlap_for` allocates a grid of size
rows * width, where rows = O(n) and width = O(n), so the grid itself
is O(n^2) cells. Marking the flipped coins and then scanning back
through the original n rows (row r has r+1 coins, so the total number
of coins is 1 + 2 + ... + n = n(n+1)/2 = O(n^2)) both take O(n^2) work.
So each shift costs O(n^2).

Multiplying the two: O(n) shifts * O(n^2) per shift = O(n^3) time
overall. The grid used for one shift at a time is O(n^2), so space
is O(n^2).

## Conclusion
Checked for n = 2 up to n = 16, the program's answer always lines up
with the formula above. For n = 4 that means 3 coins move, for n = 8
it's 12. The program does not just print the formula, it actually
works out a real set of moves that achieves it, which is a stronger
check than the number alone.
