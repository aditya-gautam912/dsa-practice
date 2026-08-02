# Trapping Rain Water — Explanation

## Approach: Two Pointers

Water trapped at each position is determined by the smaller of the max heights on its left and right. Move inward from both ends, tracking running maximums.

### Algorithm

1. `left = 0`, `right = n - 1`, track `left_max` and `right_max`.
2. While `left < right`:
   - If `height[left] < height[right]`, the left bar limits water: update `left_max` and add `left_max - height[left]` if positive; move `left` right.
   - Otherwise do the symmetric operation for `right`.
3. Return the total.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass |
| Space  | **O(1)** — no extra arrays |
