# Largest Rectangle in Histogram — Explanation

## Approach: Monotonic Stack

A rectangle's height is limited by its shortest bar. So for every bar, the largest rectangle using it as the limiting height stretches from the nearest shorter bar on the left to the nearest shorter bar on the right.

### Algorithm

1. Maintain a stack of indices whose heights are strictly increasing.
2. Iterate over every bar (plus one sentinel `0` at the end to flush the stack):
   - While the current height is smaller than the height at the stack top, pop the top bar and settle it:
     - `height` = the popped bar's height.
     - `left` = new stack top (the nearest shorter bar on the left), or `-1` if the stack is empty.
     - `width` = `current_index - left - 1`.
     - Update `maxArea`.
   - Push the current index.
3. Return `maxArea`.

The sentinel `0` at the end guarantees every bar gets settled.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each index pushed and popped at most once |
| Space  | **O(n)** — stack size |