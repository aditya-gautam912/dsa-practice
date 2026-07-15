# Next Permutation — Explanation

## Approach: Single Pass Reverse

Find the first decreasing element from the right, swap it with the next larger element to its right, then reverse the suffix.

### Algorithm

1. Find `i` from right where `nums[i] < nums[i+1]` (first dip).
2. If found, find `j` from right where `nums[j] > nums[i]` and swap.
3. Reverse the suffix from `i+1` to end.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** |
| Space  | **O(1)** |
