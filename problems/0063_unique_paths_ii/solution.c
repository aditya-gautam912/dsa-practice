/*
 * Unique Paths II (LeetCode #63, Medium)
 *
 * Follow-up to Unique Paths: some cells are obstacles (1)
 * instead of empty (0). Same DP idea — dp[j] accumulates
 * paths from above and from the left, but resets to 0
 * whenever the cell is an obstacle. Uses a 1-D rolling
 * array for O(n) space.
 */

#include <stdio.h>
#include <string.h>

/* LeetCode solution. Returns number of unique paths
 * from top-left to bottom-right avoiding obstacles. */
int uniquePathsWithObstacles(int **obstacleGrid,
                              int obstacleGridSize,
                              int *obstacleGridColSize)
{
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int dp[101];
    memset(dp, 0, sizeof(dp));

    dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[j] = 0;
                continue;
            }
            if (j > 0 && obstacleGrid[i][j] == 0)
                dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main(void)
{
    /* test 1: [[0,0,0],[0,1,0],[0,0,0]] → 2 */
    int r0[] = {0, 0, 0};
    int r1[] = {0, 1, 0};
    int r2[] = {0, 0, 0};
    int *g1[] = {r0, r1, r2};
    int c1[3] = {3, 3, 3};
    printf("grid1 -> %d (expected 2)\n", uniquePathsWithObstacles(g1, 3, c1));

    /* test 2: [[0,1],[0,0]] → 1 */
    int a0[] = {0, 1};
    int a1[] = {0, 0};
    int *g2[] = {a0, a1};
    int c2[2] = {2, 2};
    printf("grid2 -> %d (expected 1)\n", uniquePathsWithObstacles(g2, 2, c2));
    return 0;
}