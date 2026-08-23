# L4Q1-algorithm

## Aim
Given n (number, colour) pairs sorted by number, rearrange them so all reds
come first, then blues, then yellows, keeping numbers sorted within a
colour, in O(n) time.

## Algorithm
1. Start.
2. Create three empty lists, one each for red, blue and yellow.
3. Scan the input from left to right. For each item, look at its colour
   and append it to the matching list.
4. Since the input is already sorted by number and we only append, each
   list stays sorted by number on its own.
5. Join the red list, then the blue list, then the yellow list together
   to get the final output.
6. Stop.

## Pseudocode

```
procedure SORT-BY-COLOUR(items[0..n-1])
    red ← empty list
    blue ← empty list
    yellow ← empty list

    for i ← 0 to n-1
        case items[i].colour of
            RED:    APPEND(red, items[i])
            BLUE:   APPEND(blue, items[i])
            YELLOW: APPEND(yellow, items[i])
        end case
    end for

    return CONCAT(red, blue, yellow)
end procedure
```

### Time Complexity
O(n)
