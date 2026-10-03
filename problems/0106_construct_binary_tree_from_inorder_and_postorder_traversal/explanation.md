# Construct Binary Tree from Inorder and Postorder Traversal — Explanation

## Approach: Recursive Split with Hash Map

Postorder: `[left..., right..., root]`
Inorder: `[left..., root, right...]`

1. Last element of postorder is the root.
2. Find root in inorder — index `k`. Left part `[0..k-1]` is left subtree, right part `[k+1..]` is right subtree.
3. Recurse on right subtree **first** (since postorder processes right subtree before left when reading backwards), then left.

Use a hash map (array offset by 3000) for O(1) inorder index lookup.

### Algorithm

1. Build `inorderMap[value] = index` for all values in inorder.
2. Recursive function `build(inStart, inEnd)`:
   - If `inStart > inEnd`: return `NULL`.
   - `rootVal = postorder[postIndex--]` (read postorder backwards).
   - `inRoot = inorderMap[rootVal]`.
   - Create node, recurse **right first** `(inRoot+1, inEnd)`, then left `(inStart, inRoot-1)`.
3. Return root.

### Complexity

| Metric | Value |
|--------|-------|
| Time   | **O(n)** — each node processed once |
| Space  | **O(n)** — hash map + recursion stack |