# Q2 - Pair from S1 and S2 summing to x

## Files
- `L4Q2.c` - the program
- `L4Q2-algorithm.md` - pseudocode matching the code

## Approach
We sort S2 first. Then for every element a in S1, we check whether its complement, x minus a, exists in S2 using binary search. If some complement is found, we have our pair, and since the question only asks whether a pair exists, we stop right there.

## Time complexity
Let n be the size of each set.

Sorting S2: using a comparison based sort like merge sort,
Cost = O(n log n)

Checking each element of S1: there are n elements in S1, and each one needs a binary search over S2, which costs O(log n).
Cost = n × O(log n) = O(n log n)

Total time,
T(n) = O(n log n) + O(n log n) = O(n log n)

## Conclusion
The question asks for an O(n log n) algorithm to check if a pair exists, and sorting one set followed by a binary search for each element of the other set gives exactly that, instead of the O(n squared) we would get by comparing every pair directly.
