# Unique Paths II — Explanation

## Approach: 1-D DP with Obstacle Handling

Same DP as Unique Paths (#62), but cells with obstacles contribute 0 paths. Use a 1-D rolling array `dp[j]` = number of paths to reach column `j` in the current row.

### Algorithm

1. `dp[0] = 1` if the start is not an obstacle, else `0`.
2. For each row `i`, each column `j`:
   - If `obstacleGrid[i][j] == 1`: `dp[j] = 0` (blocked).
   - Else: `dp[j] += dp[j-1]` (add paths from the left).
     - `dp[j]` already holds the value from above (previous row).
3. Return `dp[n-1]`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m · n)** |
| Space  | **O(n)** — 1-D rolling array |