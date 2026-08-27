# Permutations II — Explanation

## Approach: Backtracking with Duplicate Skipping

Same swap-based backtracking as Permutations (#46), but with a duplicate-handling step. After sorting, if the current element equals the previous one AND we're at the same recursion depth (`i > start`), skip it — this avoids generating the same permutation from identical elements.

### Algorithm

1. Sort `nums`.
2. `backtrack(start)`:
   - If `start == n`: record current array.
   - For `i` from `start` to `n - 1`:
     - If `i > start && nums[i] == nums[i-1]`: continue (skip duplicate).
     - Swap `nums[start]` and `nums[i]`.
     - Recurse: `backtrack(start + 1)`.
     - Swap back.
3. Return all recorded permutations.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n! · n)** worst case (fewer if many duplicates) |
| Space  | **O(n! · n)** output + **O(n)** recursion depth |