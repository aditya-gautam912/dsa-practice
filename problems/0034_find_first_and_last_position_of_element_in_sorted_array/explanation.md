# Find First and Last Position of Element in Sorted Array — Explanation

## Approach: Binary Search (Two Passes)

Run binary search twice: once for the leftmost occurrence, once for the rightmost.

### Algorithm

1. Define `find_bound(is_left)` that searches for the target and continues narrowing.
2. For left bound: when `nums[mid] == target`, set `right = mid - 1`.
3. For right bound: when `nums[mid] == target`, set `left = mid + 1`.
4. Return `[left_bound, right_bound]`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(log n)** |
| Space  | **O(1)** |
