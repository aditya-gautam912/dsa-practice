# Sudoku Solver — Explanation

## Approach: Backtracking with Bitmasks

Find the first empty cell and try each digit `1-9` that is legal there. Place the digit, recurse, and if the recursion eventually fills every cell, we are done. If a branch reaches a dead end, undo the move and try the next digit.

### Algorithm

1. Precompute three bitmasks — `rowMask[9]`, `colMask[9]`, `boxMask[9]` — marking which digits are already used in every row, column and 3x3 box.
2. Find the first empty cell (`'.'`).
3. For each digit `d` from 1 to 9:
   - Skip if its bit is set in the cell's row, column, or box mask.
   - Place `d`, set the bits, and recurse.
   - If recursion returns `true`, propagate it up.
   - Otherwise undo the placement (clear the bits) and try the next digit.
4. If no digit fits, backtrack to the previous cell.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(9!)^9** worst case (backtracking), practically much faster due to constraints |
| Space  | **O(81)** — recursion depth + masks |