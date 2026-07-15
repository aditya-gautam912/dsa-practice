# Search Insert Position — Explanation

## Approach: Binary Search

Standard binary search. When the target isn't found, `left` points to the insertion position.

### Algorithm

1. `left = 0`, `right = len(nums) - 1`.
2. While `left <= right`:
   - If `nums[mid] == target`, return `mid`.
   - If `nums[mid] < target`, search right half.
   - Else search left half.
3. Return `left` (the insertion point).

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(log n)** |
| Space  | **O(1)** |
