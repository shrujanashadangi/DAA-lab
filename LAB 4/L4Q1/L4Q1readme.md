# Q1 - Sort n (number, colour) pairs by colour

## Files
- `L4Q1.c` - the program
- `L4Q1-algorithm.md` - pseudocode matching the code

## Approach
Since colour only takes three values, we keep three buckets, red, blue and yellow. We go through the input once and drop every pair into the bucket that matches its colour. Because the input is already sorted by number and we only add to the end of a bucket, the numbers inside each bucket stay sorted on their own. The final answer is just the three buckets placed one after another, red first, then blue, then yellow.

## Time complexity
Let n be the number of items.

Distributing items into buckets: each of the n items is looked at once and placed into a bucket in constant time.
Cost = n × O(1) = O(n)

Concatenating the buckets: the three buckets together hold exactly n items, so joining them takes
Cost = O(n)

Total time,
T(n) = O(n) + O(n) = O(n)

## Conclusion
The question asks for an O(n) algorithm, and since there are only three colours to separate, a single linear pass with three buckets is enough. No sorting step is needed at all.
