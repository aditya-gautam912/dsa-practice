# N-Queens — Explanation

## Approach: Backtracking with Column + Diagonal Tracking

Place one queen per row. For each row, try every column. Use three boolean arrays to track occupied columns and the two diagonal directions — giving O(1) attack checks. When we reach row n we have a valid placement.

### Algorithm

1. Three masks: `cols[n]`, `diag1[2n-1]` (top-left to bottom-right, index `row - col + n - 1`), `diag2[2n-1]` (top-right to bottom-left, index `row + col`).
2. `place_queens(row)`:
   - If `row == n`: record the board.
   - For `col` from 0 to n-1:
     - Skip if `cols[col]`, `diag1[row-col+n-1]`, or `diag2[row+col]` is set.
     - Set the masks, place queen, recurse `place_queens(row+1)`.
     - Unset masks (backtrack).
3. Return all recorded boards.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n!)** — pruning reduces the search space |
| Space  | **O(n)** recursion depth + output |