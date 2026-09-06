/*
 * Minimum Path Sum (LeetCode #64, Medium)
 *
 * Classic grid DP: move only right or down. Each cell's
 * minimum sum is its value plus the smaller of the sum
 * from above or from the left. Uses a 1-D rolling array
 * for O(n) space — dp[j] holds the best sum to reach
 * column j in the current row.
 */

#include <stdio.h>
#include <limits.h>

/* LeetCode solution. Returns the minimum path sum
 * from top-left to bottom-right. */
int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int m = gridSize;
    int n = gridColSize[0];
    int dp[201];           /* n <= 200 per constraints */

    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++)
        dp[j] = dp[j - 1] + grid[0][j];

    for (int i = 1; i < m; i++)
    {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++)
        {
            int fromAbove = dp[j];
            int fromLeft  = dp[j - 1];
            dp[j] = (fromAbove < fromLeft ? fromAbove : fromLeft) + grid[i][j];
        }
    }
    return dp[n - 1];
}

int main(void)
{
    /* test 1: [[1,3,1],[1,5,1],[4,2,1]] -> 7 */
    int r0[] = {1, 3, 1};
    int r1[] = {1, 5, 1};
    int r2[] = {4, 2, 1};
    int *g1[] = {r0, r1, r2};
    int c1[3] = {3, 3, 3};
    printf("grid1 -> %d (expected 7)\n", minPathSum(g1, 3, c1));

    /* test 2: [[1,2,3],[4,5,6]] -> 12 */
    int a0[] = {1, 2, 3};
    int a1[] = {4, 5, 6};
    int *g2[] = {a0, a1};
    int c2[2] = {3, 3};
    printf("grid2 -> %d (expected 12)\n", minPathSum(g2, 2, c2));
    return 0;
}