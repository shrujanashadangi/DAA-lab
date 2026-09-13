# L7Q4-algorithm

## Aim
n switches all start ON. The rightmost switch can be toggled freely.
Any other switch can be toggled only if the switch right next to it is
ON and every switch further right is OFF. Turn all switches OFF in the
minimum number of moves.

## Algorithm
1. Start.
2. T(1) = 1.
3. For n >= 2: T(n) = 2*T(n-1), plus 1 extra move if n is odd.
4. Move list for n = move list for n-1, with a toggle of switch n
   inserted after every move in it, plus one extra toggle of switch n
   at the front if n is odd.
5. Stop.

## Pseudocode

```
procedure BUILD_MOVES(n)
    if n = 1
        return [1]
    prev <- BUILD_MOVES(n-1)
    out <- []
    if n is odd
        out.append(n)
    for x in prev
        out.append(x)
        out.append(n)
    return out
```

## Time Complexity
O(T(n)) time and space to build and print the move list, O(n) to
compute the count T(n) alone.
