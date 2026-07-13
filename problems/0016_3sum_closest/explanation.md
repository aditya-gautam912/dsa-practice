# 3Sum Closest — Explanation

## Approach: Sort + Two Pointers

Same pattern as 3Sum, but instead of collecting triplets, we track the closest sum.

### Algorithm

1. Sort the array.
2. Fix `nums[i]`, use `left`/`right` pointers for the remaining range.
3. Compute `total = nums[i] + nums[left] + nums[right]`.
4. If `total` is closer to `target` than the current `closest`, update it.
5. If `total < target`, move `left` right. If `total > target`, move `right` left. If equal, return immediately.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n²)** — sorting O(n log n) + two-pointer scan O(n²) |
| Space  | **O(1)** |
