# Combination Sum II — Explanation

## Approach: Backtracking with Duplicate Skipping

Same skeleton as Combination Sum (#39), two differences:

1. **Use each candidate at most once** → recurse with `start = i + 1`.
2. **Skip duplicates** → after sorting, if `candidates[i] == candidates[i-1]` and `i > start`, skip it. This prevents generating the same combination from identical elements at the same recursion depth.

### Algorithm

1. Sort `candidates`.
2. `backtrack(start, remaining_target, path)`:
   - If `remaining_target == 0`: record `path`.
   - For `i` from `start` to `candidatesSize - 1`:
     - If `i > start && candidates[i] == candidates[i-1]`: continue (skip duplicate).
     - If `candidates[i] > remaining_target`: break (prune).
     - Append `candidates[i]` to `path`.
     - Recurse with `backtrack(i + 1, remaining_target - candidates[i], path)`.
     - Pop `path`.
3. Return all recorded paths.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(2^n · n)** worst case (subset enumeration), heavily pruned |
| Space  | **O(n)** recursion depth + output |