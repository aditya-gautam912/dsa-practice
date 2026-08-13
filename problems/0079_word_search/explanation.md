# Word Search — Explanation

## Approach: Backtracking DFS

For every cell whose letter matches the first character of `word`, start a depth-first walk. At each step, move to an up/down/left/right neighbor and try to match the next character.

### Algorithm

1. Loop over every cell `(r, c)` of the board.
2. If `board[r][c] == word[0]`, call `dfs` from there with index `k = 0`.
3. Inside `dfs`:
   - If `word[k]` is `\0`, the whole word is matched → return `true`.
   - Reject if out of bounds or letter mismatch.
   - Temporarily overwrite the current cell (e.g. `'\0'`) to mark it visited, so the same cell is never used twice in one path.
   - Recurse into the four neighbors with `k + 1`.
   - Restore the original letter before returning (backtrack), so other paths can reuse the cell.
4. If no start point succeeds, return `false`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m · n · 4^L)** — worst case explores 4 directions for each of the `L` word letters, from every cell |
| Space  | **O(L)** — recursion stack depth |