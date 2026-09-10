# Search a 2D Matrix — Explanation

## Approach: Binary Search on Flattened Array

Because each row is sorted and the first element of each row is greater than the last element of the previous row, the entire matrix is equivalent to a single sorted 1D array of length `m * n`.

### Algorithm

1. `left = 0`, `right = m * n - 1`.
2. While `left <= right`:
   - `mid = (left + right) / 2`.
   - Map `mid` to 2D: `row = mid / n`, `col = mid % n`.
   - Compare `matrix[row][col]` with `target`.
   - Adjust `left` / `right` as in standard binary search.
3. Return `true` if found, else `false`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(log(m · n))** |
| Space  | **O(1)** |