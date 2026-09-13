# L7Q4 - Security switches

## Files
- `L7Q4.c` - the program
- `L7Q4-algorithm.md` - pseudocode matching the code
- `L7Q4-readme.md` - readme (this file)

## Time complexity
From the recurrence T(n) = 2*T(n-1) + e, where e is 0 or 1, unrolling
it gives

    T(n) = 2*T(n-1) + e_n
         = 4*T(n-2) + 2*e_(n-1) + e_n
         = ...
         = 2^(n-1)*T(1) + (a sum of at most n terms, each at most 2^(n-1))

so T(n) is bounded above and below by a constant times 2^n, meaning
T(n) = Theta(2^n).

`build_moves` does O(1) work per element it copies from the previous
level plus the new interleaved switch, so the work at level n is
proportional to the length of the array it returns, which is T(n).
Summing the work across all levels:

    Time(n) = T(1) + T(2) + ... + T(n)

Since each T(i) is roughly double the one before it, this sum is
dominated by its last term, so Time(n) = O(T(n)), which is O(2^n).
Space is also O(T(n)) for storing the move list.

## Conclusion
The move list the program builds was checked against a full
state-space search for n up to 16 switches, and the counts line up
exactly every time. On top of that, the program replays its own move
list against the actual switch rule before declaring success, so it
confirms legality for whatever n is typed in, not just for the small
cases used to check the pattern.
