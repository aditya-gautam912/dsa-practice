# Pascal's Triangle — Explanation

## Approach: Iterative Row Building

Each row `i` has `i+1` elements. The first and last are always 1. Interior elements are the sum of the two elements directly above from the previous row.

### Algorithm

1. For each row `i` from 0 to `numRows-1`:
   - Allocate array of size `i+1`.
   - Set first and last element to 1.
   - For `j = 1` to `i-1`: `row[j] = prevRow[j-1] + prevRow[j]`.
2. Collect all rows.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(numRows²)** — total elements |
| Space  | **O(numRows²)** — output |