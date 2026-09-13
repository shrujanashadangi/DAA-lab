# L7Q5-algorithm

## Aim
n hiding spots sit on a line, numbered 1 to n. A target sits at one of
them and is forced to move to an adjacent spot between every two shots.
The shooter never sees it. Design a shooting order guaranteed to hit it
eventually.

## Algorithm
1. Start.
2. The target's position and the number of moves it has made always
   share the same parity.
3. Shoot spots 2, 3, ..., n-1, then n-1, n-2, ..., 2.
4. Special case n = 2: shoot the same spot twice.
5. Stop.

## Pseudocode

```
procedure SHOOTING_SEQUENCE(n)
    if n = 2
        return [1, 1]
    seq <- []
    for i <- 2 to n-1
        seq.append(i)
    for i <- n-1 downto 2
        seq.append(i)
    return seq
```

## Time Complexity
O(n) time and space to build the shooting sequence.
