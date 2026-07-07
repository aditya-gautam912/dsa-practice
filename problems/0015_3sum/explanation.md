# 3Sum — Explanation

## Approach: Sort + Two Pointers

Sorting enables efficient duplicate skipping and two-pointer traversal.

### Algorithm

1. Sort the array.
2. Fix one element `nums[i]`, then use two pointers (`left`, `right`) to find pairs that sum to `-nums[i]`.
3. Skip duplicate values at all three positions to avoid duplicate triplets.
4. When `total < 0`, move `left` right. When `total > 0`, move `right` left. When `total == 0`, record the triplet and move both pointers, skipping duplicates.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n²)** — sorting O(n log n) + two-sum for each element O(n²) |
| Space  | **O(1)** or O(n) depending on sort implementation |

### Why not brute force?

A triple nested loop is O(n³). Sorting + two pointers reduces it to O(n²) and handles duplicates cleanly.
