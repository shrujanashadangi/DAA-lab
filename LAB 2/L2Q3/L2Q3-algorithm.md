# L2Q3-algorithm

## Aim
Merge k sorted arrays of size n each into a single sorted array, using two different methods, and compare their running times.

---

## 1. Sequential Merging

### Algorithm
1. Start.
2. Take the first array as the initial result.
3. Merge the result with the second array to form a new, larger result.
4. Merge this new result with the third array.
5. Repeat step 4 for each remaining array, one at a time, until all k arrays have been merged in.
6. Stop.

### Time Complexity
O(nk²)

---

## 2. Pairwise (Tournament) Merging

### Algorithm
1. Start.
2. Pair up the k arrays: merge array 1 with array 2, array 3 with array 4, and so on. If there is an array left unpaired, carry it forward unchanged.
3. This produces roughly k/2 arrays, each about twice the size of before.
4. Repeat step 2 on this new set of arrays, pairing and merging again.
5. Continue repeating until only one array remains.
6. Stop.

### Time Complexity
O(nk log k)