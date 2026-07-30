# First Missing Positive — Explanation

## Approach: Cyclic Sort (Index Swap)

Place each number in its correct position (value `x` goes to index `x-1`). Then scan for the first mismatch.

### Algorithm

1. For each index `i`, swap `nums[i]` to `nums[nums[i]-1]` if it's in range `[1, n]` and not already in place.
2. Scan from `0` to `n-1`: the first index where `nums[i] != i+1` gives the answer `i+1`.
3. If all match, return `n + 1`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each swap places one number correctly |
| Space  | **O(1)** — in-place swaps |
