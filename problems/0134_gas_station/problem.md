# Gas Station

**LeetCode #134** | Difficulty: Medium

## Problem

There are `n` gas stations along a circular route. The amount of gas at
station `i` is `gas[i]`, and it costs `cost[i]` gas to travel from station
`i` to station `i + 1`.

Return the starting gas station's index if you can travel around the circuit
once in the clockwise direction; otherwise, return `-1`. If a solution exists,
it is guaranteed to be unique.

### Example

```
Input:  gas  = [1,2,3,4,5]
        cost = [3,4,5,1,2]
Output: 3
Explanation: Start at station 3 and complete the circuit.
```

### Constraints

- `n == gas.length == cost.length`
- `1 <= n <= 10^5`
- `0 <= gas[i], cost[i] <= 10^4`
