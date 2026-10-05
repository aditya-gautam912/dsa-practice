# Convert Sorted Array to Binary Search Tree — Explanation

## Approach: Recursive Middle Split

To ensure height balance, always pick the middle element as the root. The left half becomes the left subtree, the right half becomes the right subtree. This naturally minimizes the height difference.

### Algorithm

1. Recursive function `build(left, right)`:
   - If `left > right`: return `NULL`.
   - `mid = (left + right) / 2`.
   - Create node with `nums[mid]`.
   - Recurse left: `build(left, mid - 1)`.
   - Recurse right: `build(mid + 1, right)`.
2. Return the root.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each node visited once |
| Space  | **O(log n)** — recursion depth for balanced tree |