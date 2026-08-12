# Subsets — Explanation

## Approach: Bit Mask Iteration

There are exactly `2^n` subsets of an `n`-element set. Every subset corresponds to a bit mask of length `n` — bit `i` is 1 if element `i` is included, 0 otherwise.

### Algorithm

1. Total subsets = `2^n`.
2. For `mask = 0` to `2^n - 1`:
   - For each bit position `i` in `mask`, if bit is set, include `nums[i]` in the current subset.
   - Store the subset and its size.
3. Return all subsets.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n · 2^n)** — generate each subset |
| Space  | **O(n · 2^n)** — output size |