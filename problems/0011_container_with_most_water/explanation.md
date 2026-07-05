# Container With Most Water — Explanation

## Approach: Two Pointers

Start with two pointers at the ends of the array. The area is limited by the shorter line. Move the pointer with the shorter height inward to potentially find a taller line.

### Algorithm

1. Initialize `left = 0`, `right = len(height) - 1`, `max_water = 0`.
2. While `left < right`:
   - Compute `area = min(height[left], height[right]) * (right - left)`.
   - Update `max_water = max(max_water, area)`.
   - Move the pointer with the smaller height inward.
3. Return `max_water`.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — single pass with two pointers |
| Space  | **O(1)** — only pointers and variables |

### Why this works

Moving the taller pointer inward would never increase the area (width decreases, height capped by the shorter line). Moving the shorter pointer inward gives a chance to find a taller boundary and increase the area.
