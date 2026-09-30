# Construct Binary Tree from Preorder and Inorder Traversal — Explanation

## Approach: Recursive Split with Hash Map

Preorder: `[root, left..., right...]`
Inorder: `[left..., root, right...]`

1. First element of preorder is the root.
2. Find root in inorder — index `k`. Elements `[0..k-1]` are left subtree, `[k+1..]` are right subtree.
3. Recurse on left and right ranges.

Use a hash map (array offset by 3000) for O(1) inorder index lookup.

### Algorithm

1. Build `inorderMap[value] = index` for all values in inorder.
2. Recursive function `build(inStart, inEnd)`:
   - If `inStart > inEnd`: return `NULL`.
   - `rootVal = preorder[preIndex++]`.
   - `inRoot = inorderMap[rootVal]`.
   - Create node, recurse left `(inStart, inRoot-1)` and right `(inRoot+1, inEnd)`.
3. Return root.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each node processed once |
| Space  | **O(n)** — hash map + recursion stack |