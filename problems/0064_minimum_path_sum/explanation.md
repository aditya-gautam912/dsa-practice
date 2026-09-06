# Minimum Path Sum — Explanation

## Approach: 1-D DP for Grid Path Sum

Each cell's minimum sum = its value + min(path from above, path from left). Maintain a 1-D array `dp[j]` = min sum to reach column j in the current row.

### Algorithm

1. Initialize `dp[0] = grid[0][0]`; for `j = 1..n-1`: `dp[j] = dp[j-1] + grid[0][j]`.
2. For each subsequent row `i`:
   - `dp[0] += grid[i][0]` (only from above).
   - For `j = 1..n-1`: `dp[j] = min(dp[j], dp[j-1]) + grid[i][j]`.
3. Return `dp[n-1]`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m · n)** |
| Space  | **O(n)** — 1-D rolling array |