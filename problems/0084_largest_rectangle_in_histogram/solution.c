/*
 * Largest Rectangle in Histogram (LeetCode #84, Hard)
 *
 * Monotonic stack trick: keep a stack of indices with strictly
 * increasing heights. When we meet a bar shorter than the top of
 * the stack, that shorter bar is the "right wall" for every taller
 * bar still waiting inside, so we can settle their areas now —
 * the previous stack entry (or -1) is the "left wall". Every bar
 * is pushed once and popped once, so the whole thing is linear.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns the area of the largest rectangle
 * that can be formed inside the histogram. */
int largestRectangleArea(int *heights, int heightsSize)
{
    int *stack = (int *)malloc(heightsSize * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++)
    {
        int h = (i == heightsSize) ? 0 : heights[i]; /* sentinel 0 flushes the stack */
        while (top >= 0 && h < heights[stack[top]])
        {
            int height = heights[stack[top--]];
            int left = (top >= 0) ? stack[top] : -1;
            int width = i - left - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

int main(void)
{
    int heights1[] = {2, 1, 5, 6, 2, 3};
    printf("heights=[2,1,5,6,2,3] -> %d (expected 10)\n",
           largestRectangleArea(heights1, 6));

    int heights2[] = {2, 4};
    printf("heights=[2,4]         -> %d (expected 4)\n",
           largestRectangleArea(heights2, 2));

    int heights3[] = {2, 1, 2};
    printf("heights=[2,1,2]       -> %d (expected 3)\n",
           largestRectangleArea(heights3, 3));
    return 0;
}