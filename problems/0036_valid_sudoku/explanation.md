# Valid Sudoku — Explanation

## Approach: Bitmask Tracking

Scan the board once. For each digit, mark its presence in its row, its column and its 3x3 box using a bitmask — a 9-bit integer where digit `k` sets bit `k`. If a digit tries to set a bit that is already set in any of the three masks, the board is invalid.

### Algorithm

1. Create three masks: `rowMask[9]`, `colMask[9]`, `boxMask[9]`, all zero.
2. For every cell:
   - Skip empty cells (`'.'`).
   - Compute `bit = 1 << (digit - '1')`.
   - Compute box index: `(row / 3) * 3 + (col / 3)`.
   - If the bit is already set in the row, column, or box mask → return `false`.
   - Otherwise set the bit in all three masks.
3. Return `true` if the whole board passes.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(81) = O(1)** — fixed board size |
| Space  | **O(1)** — three fixed-size masks |