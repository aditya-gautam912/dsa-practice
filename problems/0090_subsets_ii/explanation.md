# Subsets II — Explanation

## Approach: Backtracking with Duplicate Skipping

Same backtracking as Subsets (#78), but sort the array first and skip duplicates at each recursion depth.

### Algorithm

1. Sort `nums`.
2. `backtrack(start, path)`:
   - Record current `path` as a subset.
   - For `i` from `start` to `n-1`:
     - If `i > start && nums[i] == nums[i-1]`: continue (skip duplicate at this depth).
     - Append `nums[i]` to `path`.
     - Recurse: `backtrack(i + 1, path)`.
     - Pop `path`.
3. Return all recorded subsets.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(2^n · n)** — worst case (fewer due to duplicate pruning) |
| Space  | **O(n)** recursion depth + output |