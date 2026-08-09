# L2Q2-algorithm

## Aim
Sort an array using regular merge sort (2-way split) and a modified merge sort (3-way split), and compare their running times.

---

## 1. Regular Merge Sort (2-way)

### Algorithm
1. Start.
2. If the subarray has more than one element, find the middle index.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge the two sorted halves back together: compare the front elements of both halves, copy the smaller one into the result, and repeat until both halves are exhausted.
6. Stop.

### Time Complexity
O(n log n)

---

## 2. Modified Merge Sort (3-way)

### Algorithm
1. Start.
2. If the subarray has more than one element, find two split points that divide it into three roughly equal parts.
3. Recursively sort the first third.
4. Recursively sort the second third.
5. Recursively sort the third third.
6. Merge the three sorted parts back together: compare the front elements of all three parts, copy the smallest one into the result, and repeat. Once one part runs out, finish merging the remaining two normally, then copy any leftover elements directly.
7. Stop.

### Time Complexity
O(n log n)