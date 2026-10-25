# Surrounded Regions

**LeetCode #130** | Difficulty: Medium

## Problem

Given an `m x n` matrix `board` containing `'X'` and `'O'`, capture all regions
surrounded by `'X'`.

A region is captured by flipping all `'O'` cells into `'X'` when they are
completely surrounded by `'X'`. Any `'O'` connected to the border cannot be
captured.

### Example

```
Input:
[
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","X","O","X"],
  ["X","O","X","X"]
]

Output:
[
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","O","X","X"]
]
```

### Constraints

- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`
