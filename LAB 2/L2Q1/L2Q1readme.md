# Q1 - Dictionary ADT across 6 implementations

## Files
- `L2Q1.c` - the program
- `ALGORITHM.md` - pseudocode matching the code
- `L2Q1.PNG` - chart for the graph

## Time complexity

| Operation | Unsorted Array | Sorted Array | Singly LL (unsorted) | Singly LL (sorted) | Doubly LL (unsorted) | Doubly LL (sorted) |
|---|---|---|---|---|---|---|
| Search | O(n) | O(log n) | O(n) | O(n) | O(n) | O(n) |
| Insert | O(1) | O(n) | O(1) | O(n) | O(1) | O(n) |
| Delete | O(n) | O(n) | O(n) | O(n) | O(n)* | O(n)* |
| Max | O(n) | O(1) | O(n) | O(1) | O(n) | O(1) |
| Min | O(n) | O(1) | O(n) | O(1) | O(n) | O(1) |
| Predecessor | O(n) | O(log n) | O(n) | O(n) | O(n) | O(1)** |
| Successor | O(n) | O(log n) | O(n) | O(1) | O(n) | O(1)** |

\* finding the node is O(n), unlinking it once found is O(1) (both
neighbours reachable directly). Singly linked can't do the O(1) part.

\** same idea, O(1) once you already have the node.

## Comparison

Sorted array wins on search/predecessor/successor, loses on insert.
Doubly linked sorted list wins on delete and predecessor/successor.
Unsorted structures win on insert, lose on anything that needs finding
something.

## Conclusion

Staying sorted speeds up search-type operations at the cost of insert.
Having a prev pointer speeds up delete and neighbour lookups. No
structure wins everywhere - pick based on which operations dominate.