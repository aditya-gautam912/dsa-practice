# Maximal Rectangle — Explanation

## Approach: Histogram per Row + Monotonic Stack

Treat each row as the base of a histogram. The height of column `c` is the number of consecutive `'1'`s seen vertically up to the current row. For each row, compute the largest rectangle in that histogram using the monotonic stack algorithm from LC #84. The global maximum over all rows is the answer.

### Algorithm

1. Initialize `heights[cols] = 0`, `maxArea = 0`.
2. For each row `r`:
   - For each column `c`:
     - If `matrix[r][c] == '1'`: `heights[c]++`
     - Else: `heights[c] = 0`
   - Compute largest rectangle area on `heights` using monotonic stack (LC #84).
   - Update `maxArea`.
3. Return `maxArea`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(rows · cols)** — each cell processed once, stack operations O(cols) per row |
| Space  | **O(cols)** — heights array + stack |