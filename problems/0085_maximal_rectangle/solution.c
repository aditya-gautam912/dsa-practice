/*
 * Maximal Rectangle (LeetCode #85, Hard)
 *
 * Convert each row into a histogram where heights[c] = number
 * of consecutive '1's up to this row. Then reuse the monotonic
 * stack "largest rectangle in histogram" (LC #84) algorithm
 * for every row. Track the global maximum across all rows.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int largestRectangleArea(int *heights, int n)
{
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    int maxA = 0;

    for (int i = 0; i <= n; i++)
    {
        int h = (i == n) ? 0 : heights[i];
        while (top >= 0 && h < heights[stack[top]])
        {
            int height = heights[stack[top--]];
            int left = (top >= 0) ? stack[top] : -1;
            int width = i - left - 1;
            int area = height * width;
            if (area > maxA)
                maxA = area;
        }
        stack[++top] = i;
    }
    free(stack);
    return maxA;
}

/* LeetCode solution. Returns area of largest rectangle of 1's. */
int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    if (matrixSize == 0)
        return 0;

    int n = matrixColSize[0];
    int *heights = (int *)calloc(n, sizeof(int));
    int maxArea = 0;

    for (int r = 0; r < matrixSize; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (matrix[r][c] == '1')
                heights[c]++;
            else
                heights[c] = 0;
        }
        int area = largestRectangleArea(heights, n);
        if (area > maxArea)
            maxArea = area;
    }

    free(heights);
    return maxArea;
}

int main(void)
{
    /* test 1: expected 6 */
    char *m1[] = {
        "10100",
        "10111",
        "11111",
        "10010"
    };
    int c1[4] = {5, 5, 5, 5};
    printf("test1 -> %d (expected 6)\n", maximalRectangle(m1, 4, c1));

    /* test 2: single 0 -> 0 */
    char *m2[] = {"0"};
    int c2[1] = {1};
    printf("test2 -> %d (expected 0)\n", maximalRectangle(m2, 1, c2));

    /* test 3: single 1 -> 1 */
    char *m3[] = {"1"};
    int c3[1] = {1};
    printf("test3 -> %d (expected 1)\n", maximalRectangle(m3, 1, c3));
    return 0;
}