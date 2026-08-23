# Combination Sum — Explanation

## Approach: Backtracking with Unlimited Reuse

After sorting `candidates`, we recursively build combinations. At each step we either:

1. Pick the current candidate (stay at the same index because unlimited reuse is allowed), or
2. Skip it and move to the next index.

When the running sum equals `target`, we record the path. Since the array is sorted, we can prune whenever the current candidate exceeds the remaining target.

### Algorithm

1. Sort `candidates`.
2. `backtrack(start, remaining_target, path)`:
   - If `remaining_target == 0`: record `path`.
   - For `i` from `start` to `candidatesSize - 1`:
     - If `candidates[i] > remaining_target`: break (prune).
     - Append `candidates[i]` to `path`.
     - Recurse with `backtrack(i, remaining_target - candidates[i], path)`.
     - Pop `path`.
3. Return all recorded paths.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(N^(target/min))** exponential in worst case, but pruned heavily |
| Space  | **O(target/min)** recursion depth + output |