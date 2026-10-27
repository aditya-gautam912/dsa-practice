# Gas Station — Explanation

## Approach: Greedy Reset

If the total gas is less than the total cost, completing the circuit is
impossible. Otherwise, scan the stations while tracking the current fuel.
Whenever the fuel becomes negative, the current starting point cannot work,
and no station between it and the current station can work either, so restart
from the next station.

### Algorithm

1. Track `total` as the sum of `gas[i] - cost[i]`.
2. Track `tank` from the current candidate start.
3. If `tank` becomes negative at station `i`, set the next station as the
   candidate start and reset `tank`.
4. Return the candidate start if `total >= 0`; otherwise return `-1`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** |
| Space  | **O(1)** |
