# Remove Element — Explanation

## Approach: Two Pointers (In-Place)

Use `k` as the placement pointer. Iterate through the array; whenever an element is not equal to `val`, write it at index `k` and increment `k`.

### Algorithm

1. Initialize `k = 0`.
2. For each `i` in range `0` to `n-1`:
   - If `nums[i] != val`, set `nums[k] = nums[i]` and increment `k`.
3. Return `k`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — in-place |
