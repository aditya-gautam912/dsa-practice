# Merge Sorted Array — Explanation

## Approach: Three-Pointer Reverse Fill

Since `nums1` has enough space at the end, merge from the back. Compare the largest remaining elements of `nums1` (index `m-1`) and `nums2` (index `n-1`), and place the larger one at the end of `nums1` (index `m+n-1`). This avoids overwriting unprocessed elements in `nums1`.

### Algorithm

1. `i = m - 1`, `j = n - 1`, `k = m + n - 1`.
2. While `i >= 0 && j >= 0`:
   - If `nums1[i] > nums2[j]`: `nums1[k--] = nums1[i--]`
   - Else: `nums1[k--] = nums2[j--]`
3. Copy any remaining elements from `nums2` (if `j >= 0`).
4. Done — `nums1` is now fully sorted.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(m + n)** |
| Space  | **O(1)** — in-place |