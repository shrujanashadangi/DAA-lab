# L3Q2-algorithm

## Aim
Given `n` coins that are all identical in weight except possibly one which is
lighter (or none at all), find the lighter (defective) coin — or correctly
report that none exists — using a balance scale, in `⌊log₂ n⌋ + c` weighings.

---

## Algorithm — `findFake(coins, lo, hi, ref)`
`ref` is the index of a coin already known to be genuine, or -1 if no such
coin is known yet.

1. Start.
2. Let `n = hi - lo + 1` be the number of coins currently under
   consideration.
3. If `n = 1` (a single candidate coin remains):
   - If no reference coin is known yet, there is nothing to compare
     against — report that **no defective coin exists**.
   - Otherwise, weigh the single coin against the reference coin: if it is
     lighter, it is the defective coin; otherwise report **no defective
     coin**.
4. If `n > 1`, split the coins into a left group `L` of size `⌊n/2⌋` and an
   equally sized right group `R` starting right after `L`. (If `n` is odd,
   one coin is left over, unweighed, for now.)
5. Weigh `L` against `R` on the balance scale.
6. If the pans balance, no defective coin exists among the `2·⌊n/2⌋` coins
   just weighed. If a coin was left over (`n` was odd), weigh it against
   any coin from `L` or `R` (now proven genuine) to check whether it is the
   defective one; otherwise report **no defective coin**.
7. If the left pan is lighter, the defective coin lies in `L`. Recurse into
   `L`, using any coin of `R` as the reference — since `R` balanced
   heavier, every coin in it is now proven genuine.
8. If the right pan is lighter, the defective coin lies in `R`. Recurse
   into `R`, using any coin of `L` as the reference, by the same reasoning.
9. Stop. The recursion terminates when a single coin remains (step 3).

### Time Complexity
Recurrence: `T(n) = T(⌈n/2⌉) + O(1)`, `T(1) = O(1)` ⇒ `T(n) = O(log₂ n)`,
in practice `⌊log₂ n⌋ + c` weighings.
