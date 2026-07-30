# Median of Two Sorted Arrays — Explanation

## Approach: Binary Search on Partition

Binary search the smaller array to find a partition that splits both arrays into left and right halves where all left elements ≤ all right elements.

### Algorithm

1. Ensure `nums1` is the smaller array.
2. Binary search `i` (cut position in `nums1`), derive `j = half - i` (cut in `nums2`).
3. Check if `max(left1, left2) <= min(right1, right2)`.
4. If yes, compute median based on even/odd total length.
5. If `left1 > right2`, move `i` left; if `left2 > right1`, move `i` right.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(log(min(m, n)))** |
| Space  | **O(1)** |
