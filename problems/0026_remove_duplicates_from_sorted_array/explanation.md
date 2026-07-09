# Remove Duplicates from Sorted Array — Explanation

## Approach: Two Pointers (In-Place)

Use one pointer `k` to track where the next unique element should go, and iterate `i` through the array.

### Algorithm

1. If array is empty, return 0.
2. Start `k = 1` (first element is always unique).
3. For `i` from 1 to `n-1`:
   - If `nums[i] != nums[i-1]`, place `nums[i]` at index `k` and increment `k`.
4. Return `k`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — in-place |
