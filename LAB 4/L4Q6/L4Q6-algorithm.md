# L4Q6-algorithm

## Aim
Given n intervals on a line, identify a point p covered by the largest
number of intervals, in O(n log n) time. Endpoints count as covered
(intervals are closed).

## Algorithm
1. Start.
2. For each interval, create a start event at its left endpoint and an
   end event at its right endpoint.
3. Sort all events by position. If a start and an end land on the same
   point, place the start event before the end event.
4. Sweep through the sorted events, increasing a running count by 1 at
   every start event and decreasing it by 1 at every end event.
5. Keep track of the highest count seen so far and the point at which it
   occurred.
6. Report this point along with the count as the answer.
7. Stop.

## Pseudocode

```
procedure MAX-POINT-COVERAGE(intervals[0..n-1])
    E ← empty list

    for each (l, r) ∈ intervals
        APPEND(E, (l, START))
        APPEND(E, (r, END))
    end for

    SORT(E) by point, START before END on ties

    count ← 0
    best ← 0
    bestPoint ← E[0].point

    for each event ∈ E, in sorted order
        if event.type = START
            count ← count + 1
            if count > best
                best ← count
                bestPoint ← event.point
            end if
        else
            count ← count - 1
        end if
    end for

    return (bestPoint, best)
end procedure
```

### Time Complexity
O(n log n)
