# Candy — Explanation

## Approach: Two Directional Passes

First scan from left to right and ensure every child with a higher rating than
the left neighbor gets one more candy. Then scan from right to left and ensure
the same rule holds for the right neighbor. For each child, keep the larger
requirement from the two passes.

### Algorithm

1. Initialize every child's candy count to `1`.
2. Scan left to right; increase `candies[i]` when `ratings[i]` is greater than
   `ratings[i - 1]`.
3. Scan right to left; increase `candies[i]` to at least
   `candies[i + 1] + 1` when `ratings[i]` is greater than `ratings[i + 1]`.
4. Return the sum of all candy counts.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** |
| Space  | **O(n)** |
