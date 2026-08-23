# L4Q4-algorithm

## Aim
Given entry time a_i and exit time b_i for n persons at a party, find the
time at which the maximum number of people were simultaneously present,
in O(n log n) time.

## Algorithm
1. Start.
2. For each person, create two events, one at the entry time marked +1
   and one at the exit time marked -1.
3. Sort all the events by time.
4. Sweep through the sorted events, keeping a running count that
   increases by 1 at every entry event and decreases by 1 at every exit
   event.
5. Keep track of the highest count seen so far and the time at which it
   occurred.
6. Report this time along with the count as the answer.
7. Stop.

## Pseudocode

```
procedure MAX-SIMULTANEOUS(a[0..n-1], b[0..n-1])
    E ← empty list

    for i ← 0 to n-1
        APPEND(E, (a[i], +1))
        APPEND(E, (b[i], -1))
    end for

    SORT(E) by time

    count ← 0
    best ← 0
    bestTime ← E[0].time

    for each event ∈ E, in sorted order
        count ← count + event.delta
        if count > best
            best ← count
            bestTime ← event.time
        end if
    end for

    return (bestTime, best)
end procedure
```

### Time Complexity
O(n log n)
