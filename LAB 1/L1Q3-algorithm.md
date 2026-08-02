L1Q3-algorithm

## Aim
Compare the performance of optimized Bubble Sort and regular Bubble Sort by counting the number of comparisons.

## Algorithm

1. Start.
2. Read the size of the array.
3. Generate random elements for the array.
4. Create a copy of the original array.
5. Apply optimized Bubble Sort:
   - Compare adjacent elements.
   - Swap if required.
   - Stop early if no swaps occur in a pass.
   - Count the number of comparisons.
6. Restore the original array.
7. Apply regular Bubble Sort:
   - Perform exactly (n − 1) passes.
   - Compare adjacent elements.
   - Swap if required.
   - Count the number of comparisons.
8. Display the comparison counts of both methods.
9. Stop.

## Time Complexity
O(n²)

