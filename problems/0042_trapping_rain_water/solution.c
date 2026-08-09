/*
 * LeetCode #42: Trapping Rain Water
 * Difficulty: Hard
 *
 * Human approach:
 * Water collects where a dip is enclosed by taller walls. Move two
 * pointers from the two ends inward. Whichever side has the lower wall is
 * the one that decides water height, so we always move the shorter side
 * and add the water collected above it.
 */

#include <stdio.h>

/* LeetCode solution. */
int trap(int *height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                total += leftMax - height[left];
            left++;
        }
        else
        {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                total += rightMax - height[right];
            right--;
        }
    }
    return total;
}

int main(void)
{
    int h1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int h2[] = {4, 2, 0, 3, 2, 5};

    printf("Test 1: %d\n", trap(h1, 12)); /* 6 */
    printf("Test 2: %d\n", trap(h2, 6));  /* 9 */
    return 0;
}