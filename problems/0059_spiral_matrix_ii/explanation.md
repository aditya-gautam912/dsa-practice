# Spiral Matrix II — Explanation

## Approach: Shrinking Boundary Fill

Same shrinking-rectangle traversal as Spiral Matrix (#54), but instead of reading, we write values 1 through n² in order.

### Algorithm

1. Initialize `top = 0`, `bottom = n - 1`, `left = 0`, `right = n - 1`, `val = 1`.
2. While `val <= n²`:
   - Walk **right** across row `top` → fill `val++`. Increment `top`.
   - Walk **down** column `right` → fill `val++`. Decrement `right`.
   - Walk **left** across row `bottom` → fill `val++`. Decrement `bottom`.
   - Walk **up** column `left` → fill `val++`. Increment `left`.
3. Return the filled matrix.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n²)** — every cell visited once |
| Space  | **O(1)** — output matrix excluded |