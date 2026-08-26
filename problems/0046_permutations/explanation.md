# Permutations — Explanation

## Approach: Backtracking by Swapping

Generate all permutations by fixing each remaining element at the current position, recursing on the rest, then swapping back to restore the array for the next branch.

### Algorithm

1. `backtrack(start)`:
   - If `start == numsSize`: copy the current array as a complete permutation.
   - For `i` from `start` to `numsSize - 1`:
     - Swap `nums[start]` and `nums[i]`.
     - Recurse: `backtrack(start + 1)`.
     - Swap back (restore).
2. Return all recorded permutations.

The number of permutations is `n!`, precomputed for allocation.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n! · n)** — n! permutations, each copied in O(n) |
| Space  | **O(n! · n)** output + **O(n)** recursion depth |