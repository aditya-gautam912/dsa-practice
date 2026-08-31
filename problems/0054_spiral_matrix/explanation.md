# Spiral Matrix — Explanation

## Approach: Shrinking Boundary Traversal

Maintain four boundaries: `top`, `bottom`, `left`, `right`. Walk the perimeter of the current rectangle and shrink the boundaries inward after each loop.

### Algorithm

1. Initialize `top = 0`, `bottom = rows - 1`, `left = 0`, `right = cols - 1`.
2. While not all elements visited:
   - Walk **right** across row `top` (columns `left..right`). Increment `top`.
   - Walk **down** column `right` (rows `top..bottom`). Decrement `right`.
   - Walk **left** across row `bottom` (columns `right..left`). Decrement `bottom`.
   - Walk **up** column `left` (rows `bottom..top`). Increment `left`.
3. Return the collected elements.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m · n)** — every cell visited once |
| Space  | **O(1)** — output array excluded |