# L7Q6-algorithm

## Aim
Given the birth and death years of n scientists, find the year when the
largest number of them were alive at the same time.

## Algorithm
1. Start.
2. Turn each birth into a +1 event and each death into a -1 event.
3. Sort all 2n events by year, deaths before births on a tie.
4. Sweep through the events, tracking a running alive count and its
   maximum.
5. Return the maximum and the year it is first reached.
6. Stop.

## Pseudocode

```
procedure BEST_YEAR(births, deaths, n)
    events <- []
    for i <- 1 to n
        events.append( (births[i],  +1, order 1) )
        events.append( (deaths[i],  -1, order 0) )
    sort events by year, ties broken by order (deaths before births)

    alive <- 0, best <- 0, bestYear <- none
    for each (year, delta, _) in events
        alive <- alive + delta
        if alive > best
            best <- alive
            bestYear <- year
    return best, bestYear
```

## Time Complexity
O(n log n) time, O(n) space.
