# Q6 - Point covered by the maximum number of intervals

## Files
- `L4Q6.c` - the program
- `L4Q6-algorithm.md` - pseudocode matching the code

## Approach
Every left endpoint becomes a start event and every right endpoint becomes an end event. These events are sorted by position, with start events placed before end events when they land on the same point, since the intervals are closed and that shared point should count as covered by both. We then sweep through the sorted events, increasing a counter at every start and decreasing it at every end, keeping track of the highest count seen and the point where it happened.

## Time complexity
Let n be the number of intervals, so there are 2n events in total.

Building the events: each interval contributes exactly two events.
Cost = O(n)

Sorting the events: sorting 2n events,
Cost = O(2n log 2n) = O(n log n)

Sweeping through the events: each event is visited once.
Cost = O(n)

Total time,
T(n) = O(n) + O(n log n) + O(n) = O(n log n)

## Conclusion
The question asks for an O(n log n) algorithm, and turning the endpoints into events and sweeping through them sorted gets us there, since the coverage count can only ever change at one of these 2n points.
