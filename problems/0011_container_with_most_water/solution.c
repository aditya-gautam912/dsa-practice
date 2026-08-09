/*
 * LeetCode #11: Container With Most Water
 * Difficulty: Medium
 *
 * Human approach:
 * Imagine the tallest walls at both ends. The water is limited by the
 * shorter wall. So we start with the widest container (two ends), compute
 * the water, then move the shorter side inward hoping the next wall is
 * taller. We repeat and always remember the biggest amount of water.
 */

#include <stdio.h>

/* LeetCode solution. */
int maxArea(int *height, int heightSize)
{
    int left = 0, right = heightSize - 1;
    int maxWater = 0;

    while (left < right)
    {
        int currentHeight = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int water = currentHeight * width;
        if (water > maxWater)
            maxWater = water;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxWater;
}

int main(void)
{
    int h1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int h2[] = {1, 1};

    printf("Test 1: %d\n", maxArea(h1, 9)); /* 49 */
    printf("Test 2: %d\n", maxArea(h2, 2)); /* 1 */
    return 0;
}