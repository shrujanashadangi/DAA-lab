LIQ2-algorithm

## Aim
Simulate fair and biased coin tosses and compare their probabilities of obtaining heads.

## Algorithm

1. Start.
2. Read the number of coin tosses (N).
3. Read the probability (p) of obtaining heads for the biased coin.
4. Initialize the head counts for both coins to zero.
5. Repeat N times:
   - Generate a random number for the fair coin.
   - If it is less than 0.5, increment the fair coin head count.
   - Generate another random number for the biased coin.
   - If it is less than p, increment the biased coin head count.
6. Calculate the fraction of heads for both coins.
7. Display the probabilities obtained.
8. Stop.

## Time Complexity
O(N)

