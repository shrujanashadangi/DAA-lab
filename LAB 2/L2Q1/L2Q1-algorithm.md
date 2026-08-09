# L2Q1-algorithm

## Aim
Implement the dictionary ADT (search, insert, delete, min, max, predecessor, successor) using six different underlying data structures, and compare them.

---

## 1. Unsorted Array

### Algorithm
1. Start.
2. To search for a key, scan the array from index 0 to size-1 and compare each element with the key. Return the index if found, else return -1.
3. To insert a value, place it at index `size` and increment `size` by 1.
4. To delete a value, first search for it. If found, copy the last element into its position and decrement `size` by 1.
5. Stop.

### Time Complexity
Search: O(n) | Insert: O(1) | Delete: O(n)

---

## 2. Sorted Array

### Algorithm
1. Start.
2. To search for a key, use binary search: repeatedly compare the key with the middle element and narrow the search to the left or right half.
3. To insert a value, find the correct position by shifting all larger elements one step to the right, then place the value.
4. To delete a value, search for it, then shift all elements after it one step to the left.
5. Stop.

### Time Complexity
Search: O(log n) | Insert: O(n) | Delete: O(n)

---

## 3. Singly Linked List - Unsorted

### Algorithm
1. Start.
2. To search for a key, start at the head and move node by node until the key is found or the list ends.
3. To insert a value, create a new node and place it at the front of the list (new node points to the old head).
4. To delete a value, if the head holds the value remove it directly. Otherwise walk the list keeping track of the previous node until the node to delete is found, then unlink it.
5. Stop.

### Time Complexity
Search: O(n) | Insert: O(1) | Delete: O(n)

---

## 4. Singly Linked List - Sorted

### Algorithm
1. Start.
2. To search for a key, start at the head and move node by node until the key is found or a larger value is reached.
3. To insert a value, walk the list until the correct position is found (the point where the next node's value is no longer smaller), then insert the new node there to keep the list sorted.
4. To delete a value, walk the list to find the node before the target, then unlink the target node.
5. Stop.

### Time Complexity
Search: O(n) | Insert: O(n) | Delete: O(n)

---

## 5. Doubly Linked List - Unsorted

### Algorithm
1. Start.
2. To search for a key, start at the head and move node by node (using the next pointer) until the key is found.
3. To insert a value, create a new node and place it at the front, updating both the next and prev pointers.
4. To delete a value, search for the node. Once found, unlink it directly using its own prev and next pointers - no need to walk back to find the previous node.
5. Stop.

### Time Complexity
Search: O(n) | Insert: O(1) | Delete: O(n) to find + O(1) to unlink

---

## 6. Doubly Linked List - Sorted

### Algorithm
1. Start.
2. To search for a key, start at the head and move node by node until the key is found or a larger value is reached.
3. To insert a value, walk the list to find the correct position, then insert the node there, updating both prev and next pointers of its neighbours.
4. To delete a value, search for the node, then unlink it directly using its prev and next pointers.
5. Stop.

### Time Complexity
Search: O(n) | Insert: O(n) | Delete: O(n) to find + O(1) to unlink

---

## 7. Min and Max

### Algorithm
1. Start.
2. Since the sorted array is always kept in increasing order, the minimum is the first element and the maximum is the last element.
3. Read `sorted_arr[0]` for the minimum and `sorted_arr[size-1]` for the maximum.
4. Stop.

### Time Complexity
O(1)

---

## 8. Predecessor and Successor

### Algorithm
1. Start.
2. Search for the given value x in the doubly linked sorted list.
3. If found, the predecessor is the value stored in the node's prev pointer (if it exists).
4. The successor is the value stored in the node's next pointer (if it exists).
5. Stop.

### Time Complexity
O(n) to find the node + O(1) to read predecessor/successor