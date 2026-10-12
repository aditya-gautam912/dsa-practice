# Pascal's Triangle II — Explanation

## Approach: In-Place Row Building (O(k) Space)

Build the target row iteratively. Start with `[1]`. For each new row `i` from 1 to `rowIndex`, update the array from right to left: `row[j] = row[j] + row[j-1]`. This avoids overwriting values that are still needed.

### Algorithm

1. Allocate `row[rowIndex + 1]` initialized to 0.
2. `row[0] = 1`.
3. For `i = 1` to `rowIndex`:
   - For `j = i` down to 1: `row[j] += row[j-1]`.
4. Return `row`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(rowIndex²)** |
| Space  | **O(rowIndex)** — output array only |