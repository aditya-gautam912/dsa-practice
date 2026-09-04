# Unique Paths II

**LeetCode #63** | Difficulty: Medium

## Problem

A robot is located at the top-left corner of an `m x n` grid. The robot can only move either down or right at any point in time. The robot tries to reach the bottom-right corner of the grid.

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space are marked as `1` or `0` respectively in the grid.

### Example

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
```

### Constraints

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.