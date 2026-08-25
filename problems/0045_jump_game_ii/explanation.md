# Jump Game II — Explanation

## Approach: Greedy Single Pass

Maintain the farthest index reachable with the current number of jumps (`currentEnd`) and the farthest index reachable with one additional jump (`farthest`). When we reach `currentEnd`, we must make another jump and update `currentEnd = farthest`.

### Algorithm

1. `jumps = 0`, `currentEnd = 0`, `farthest = 0`.
2. For `i = 0` to `n - 2` (no need to jump from the last index):
   - `farthest = max(farthest, i + nums[i])`.
   - If `i == currentEnd`:
     - `jumps++`
     - `currentEnd = farthest`
     - If `currentEnd >= n - 1`: break (we can reach the end).
3. Return `jumps`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — constant extra space |