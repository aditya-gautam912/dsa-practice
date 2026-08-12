# Sort Colors — Explanation

## Approach: Dutch National Flag (Three Pointers)

Partition the array into three regions while scanning once. `lo` marks the boundary of 0s, `hi` the boundary of 2s, and `mid` walks through.

### Algorithm

1. `lo = 0`, `mid = 0`, `hi = n - 1`.
2. While `mid <= hi`:
   - `nums[mid] == 0`: swap with `nums[lo]`, advance both.
   - `nums[mid] == 2`: swap with `nums[hi]`, only move `hi` (re-check what came back).
   - otherwise (`1`): just advance `mid`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — in-place |
