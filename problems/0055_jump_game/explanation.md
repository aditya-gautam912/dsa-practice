# Jump Game — Explanation

## Approach: Greedy Single Pass

Track the farthest index reachable so far. Walk the array left to right. At each index, if it is beyond the farthest reachable point, we are stuck. Otherwise update the farthest reach from this index. If farthest reaches the last index, return true.

### Algorithm

1. `farthest = 0`.
2. For `i = 0` to `numsSize - 1`:
   - If `i > farthest`: return `false`.
   - If `farthest >= numsSize - 1`: return `true`.
   - `farthest = max(farthest, i + nums[i])`.
3. Return `true`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — constant extra space |