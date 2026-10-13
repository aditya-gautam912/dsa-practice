/*
 * Triangle (LeetCode #120, Medium)
 *
 * Bottom-up DP: start from the second-last row, for each
 * element add the minimum of the two reachable elements in
 * the row below. Overwrite the triangle in-place. The top
 * element becomes the minimum path sum.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns minimum path sum from top to bottom. */
int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    for (int i = triangleSize - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangleColSize[i]; j++)
        {
            triangle[i][j] += (triangle[i + 1][j] < triangle[i + 1][j + 1])
                ? triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }
    return triangle[0][0];
}

int main(void)
{
    /* test 1: [[2],[3,4],[6,5,7],[4,1,8,3]] -> 11 */
    int r0[] = {2};
    int r1[] = {3, 4};
    int r2[] = {6, 5, 7};
    int r3[] = {4, 1, 8, 3};
    int *t1[] = {r0, r1, r2, r3};
    int c1[4] = {1, 2, 3, 4};
    printf("test1 -> %d (expected 11)\n", minimumTotal(t1, 4, c1));

    /* test 2: [[-10]] -> -10 */
    int r4[] = {-10};
    int *t2[] = {r4};
    int c2[1] = {1};
    printf("test2 -> %d (expected -10)\n", minimumTotal(t2, 1, c2));
    return 0;
}