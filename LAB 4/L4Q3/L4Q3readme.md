# Q3 - k elements of S summing to T

## Files
- `L4Q3.c` - the program
- `L4Q3-algorithm.md` - pseudocode matching the code

## Approach
We sort S first. Then we pick the first k minus 2 numbers one at a time using nested loops written as recursion, always moving forward so we never reuse an index. Once only two numbers are left to choose, instead of using two pointers, we scan through the remaining numbers and binary search for the exact complement needed to hit the target.

## Time complexity
Let n be the size of S and k be the number of elements we are choosing.

Sorting S: O(n log n)

Fixing the first k minus 2 numbers: this is done with k minus 2 nested loops, each running over roughly n values, so the number of combinations tried is
Cost = O(n^(k-2))

Solving the last two numbers for each combination: this step scans up to n values, and for each one does a binary search costing O(log n).
Cost = n × O(log n) = O(n log n)

Since the last step runs once for every combination of the first k minus 2 numbers,
T(n) = O(n log n) + O(n^(k-2)) × O(n log n)
     = O(n log n) + O(n^(k-1) log n)
     = O(n^(k-1) log n)

(the O(n log n) sorting term is dominated by O(n^(k-1) log n) since k is at least 2)

## Conclusion
The question asks specifically for O(n^(k-1) log n), and that is exactly what we get by fixing k minus 2 numbers directly and solving the remaining two with a binary search instead of a two pointer scan.
