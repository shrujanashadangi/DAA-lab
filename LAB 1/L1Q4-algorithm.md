LIQ4-algorithm

## Aim
Solve the Tower of Hanoi problem recursively and determine the total number of moves.

## Algorithm

1. Start.
2. Read the number of disks (n).
3. If n is 0, return.
4. Move the top (n − 1) disks from the source rod to the auxiliary rod.
5. Move the largest disk from the source rod to the destination rod.
6. Move the (n − 1) disks from the auxiliary rod to the destination rod.
7. Count each move.
8. Display the sequence of moves (for small values of n) and the total number of moves.
9. Stop.

## Time Complexity
O(2ⁿ)
