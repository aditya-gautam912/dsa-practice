# Search in Rotated Sorted Array — Explanation

## Approach: Modified Binary Search

Compare `nums[mid]` with `nums[left]` to determine which half is sorted, then narrow the search accordingly.

### Algorithm

1. While `left <= right`, compute `mid`.
2. If `nums[mid] == target`, return.
3. If left half is sorted (`nums[left] <= nums[mid]`):
   - If target is in left half, search left; else search right.
4. Else right half is sorted:
   - If target is in right half, search right; else search left.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(log n)** |
| Space  | **O(1)** |
