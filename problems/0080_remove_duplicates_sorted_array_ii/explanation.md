# Remove Duplicates from Sorted Array II — Explanation

## Approach: Two-Pointer with At-Most-Twice Rule

Since the array is sorted, duplicates are adjacent. We allow each value to appear at most twice by checking whether including it would be the third copy.

### Algorithm

1. Write pointer `k = 0`.
2. For each read index `i`:
   - If `k < 2`: always keep (first two slots always valid).
   - Else if `nums[i] > nums[k - 2]`: keep — this value hasn't appeared twice yet at the front.
   - Else: skip (would be a third+ duplicate).
3. Return `k`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — in-place |