# Q4 - Time of maximum occupancy at a party

## Files
- `L4Q4.c` - the program
- `L4Q4-algorithm.md` - pseudocode matching the code

## Approach
Every entry time is turned into a plus one event and every exit time into a minus one event. All these events are sorted by time, and then we sweep through them in order, keeping a running count of how many people are present. Whenever the count goes higher than anything seen before, we record that count and the time it happened at.

## Time complexity
Let n be the number of persons, so there are 2n events in total.

Building the events: each person contributes exactly two events.
Cost = O(n)

Sorting the events: sorting 2n events with a comparison based sort,
Cost = O(2n log 2n) = O(n log n)

Sweeping through the events: each event is visited once.
Cost = O(n)

Total time,
T(n) = O(n) + O(n log n) + O(n) = O(n log n)

## Conclusion
The question asks for an O(n log n) algorithm, and converting arrivals and departures into signed events and sorting them gets us there, since the peak occupancy can only ever change at one of these 2n moments.
