# L7Q3 - Reve's puzzle (4-peg Tower of Hanoi)

## Files
- `L7Q3.c` - the program
- `L7Q3-algorithm.md` - pseudocode matching the code
- `L7Q3-readme.md` - readme (this file)

## Time complexity
Building the T4 table: the outer loop runs for m = 2 to n, and for
each m the inner loop over k runs m-1 times. Adding these up:

    sum_{m=2}^{n} (m-1) = 1 + 2 + ... + (n-1) = n(n-1)/2 = O(n^2)

so building the table takes O(n^2) time and O(n) space for the T4 and
split arrays.

Printing the moves: each recursive call to FRAME_STEWART or HANOI3
does O(1) work per move it prints, and the total number of moves
printed is exactly T4(n) by construction, so printing takes O(T4(n))
time.

## Conclusion
For 8 disks the program comes out to exactly 33 moves, which is the
number given in the problem statement. The table of move counts for
n = 1 through 8 (1, 3, 5, 9, 13, 17, 25, 33) matches the standard
Frame-Stewart sequence for 4-peg Hanoi, and the same algorithm works
for any number of disks since the split point is worked out fresh for
each n.
