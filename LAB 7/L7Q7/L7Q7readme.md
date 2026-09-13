# L7Q7 - Matrix Chain Multiplication

## Files
- `L7Q7.c` - the program
- `L7Q7-algorithm.md` - pseudocode matching the code
- `L7Q7-readme.md` - readme (this file)

## Time complexity
The outer two loops run over every pair (i, j) with i <= j, and there
are O(n^2) such pairs (chain length from 2 to n, and for each length
up to n starting points). For each pair, the innermost loop tries
every split point k from i to j-1, which is at most n values.

Multiplying the number of pairs by the work per pair:

    O(n^2) pairs * O(n) split points per pair = O(n^3)

so filling the table takes O(n^3) time. The tables m and s are both
(n+1) x (n+1), so space is O(n^2).

## Conclusion
Run on the standard textbook example (dimensions 30, 35, 15, 5, 10,
20, 25 for 6 matrices), the program comes out to 15125 scalar
multiplications with the parenthesization ((A1(A2A3))((A4A5)A6)),
which is the widely published answer for that exact example.
