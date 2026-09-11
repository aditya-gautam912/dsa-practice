# Search in Rotated Sorted Array II — Explanation

## Approach: Modified Binary Search with Duplicate Shrinking

Same core idea as #33, but duplicates create ambiguity. When `nums[left] == nums[mid] == nums[right]`, we cannot tell which half is sorted, so we shrink both ends by one. Otherwise we determine which half is sorted and binary search within it.

### Algorithm

1. `left = 0`, `right = n - 1`.
2. While `left <= right`:
   - If `nums[mid] == target`: return `true`.
   - If `nums[left] == nums[mid] == nums[right]`: `left++`, `right--` (shrink ambiguous region).
   - Else if left half `[left..mid]` is sorted (`nums[left] <= nums[mid]`):
     - If `target` is in `[nums[left], nums[mid])`: `right = mid - 1`.
     - Else: `left = mid + 1`.
   - Else right half is sorted:
     - If `target` is in `(nums[mid], nums[right]]`: `left = mid + 1`.
     - Else: `right = mid - 1`.
3. Return `false` if not found.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** worst case (all duplicates), **O(log n)** average |
| Space  | **O(1)** |