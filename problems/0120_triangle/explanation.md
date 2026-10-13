# Triangle — Explanation

## Approach: Bottom-Up DP (In-Place)

Start from the second-last row. For each element, add the minimum of the two reachable elements in the row below. Overwrite the triangle array in-place. The top element ends up holding the minimum path sum.

### Algorithm

1. For `i` from `triangleSize - 2` down to `0`:
   - For `j` from `0` to `triangleColSize[i] - 1`:
     - `triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])`
2. Return `triangle[0][0]`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n²)** — n = number of rows |
| Space  | **O(1)** — modifies input in place |