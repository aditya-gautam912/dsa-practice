# Surrounded Regions — Explanation

## Approach: Mark Border-Connected Regions

An `'O'` can remain only if it is connected to an `'O'` on the border.
Starting from every border `'O'`, traverse its region and temporarily mark
each reachable cell as `'T'`. After all border-connected regions are marked,
flip the remaining `'O'` cells to `'X'`, then restore `'T'` cells to `'O'`.

### Algorithm

1. Traverse every cell on the four borders.
2. For each border `'O'`, use an iterative depth-first search to mark its
   connected region with `'T'`.
3. Scan the board:
   - Flip `'O'` to `'X'`.
   - Restore `'T'` to `'O'`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m × n)** |
| Space  | **O(m × n)** in the worst case for the traversal stack |
