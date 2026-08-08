# Set Matrix Zeroes — Explanation

## Approach: In-Place Markers

Use the first row and first column as markers to remember which rows/columns need zeroing, avoiding extra memory.

### Algorithm

1. Record whether the first row and first column originally contain a zero.
2. For each `matrix[i][j] == 0` (i > 0, j > 0), set `matrix[i][0] = 0` and `matrix[0][j] = 0`.
3. Zero out interior cells where the row or column marker is 0.
4. Zero out the first row / first column if they originally contained a zero.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m · n)** — scan the matrix a few times |
| Space  | **O(1)** — marker approach, no extra matrix |