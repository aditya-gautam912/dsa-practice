# Rotate Image — Explanation

## Approach: Transpose + Reverse Rows

Rotating 90 degrees clockwise equals transposing the matrix, then reversing each row.

### Algorithm

1. Transpose: for `i` in range(n), for `j` in range(i+1, n), swap `matrix[i][j]` and `matrix[j][i]`.
2. Reverse each row in place.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n²)** — every element visited once for transpose and once for reverse |
| Space  | **O(1)** — in-place |
