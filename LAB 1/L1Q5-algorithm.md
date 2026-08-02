L1Q5-algorithm

## Aim
Find the partition point where 0s change to 1s in a binary array using Binary Search.

## Algorithm

1. Start.
2. Read the number of elements.
3. Read the binary array.
4. Verify that all 0s appear before all 1s.
5. Initialize low = 0 and high = n − 1.
6. Perform Binary Search:
   - Find the middle element.
   - If the middle element is 1, record its index and search the left half.
   - Otherwise, search the right half.
7. Display the partition point.
8. Stop.

## Time Complexity
O(log n)
