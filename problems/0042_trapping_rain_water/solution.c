/*
 * Trapping Rain Water (LeetCode #42, Hard)
 *
 * Water sits in dips. At each position the water level is decided
 * by the shorter of the two tallest walls beside it. Move the two
 * pointers inward from the ends; the side with the shorter wall is
 * always the safe one to compute on. This avoids arrays of
 * left-max and right-max entirely - one pass, constant memory.
 */

#include <stdio.h>

int trap(int *height, int heightSize)
{
    int lo = 0, hi = heightSize - 1;
    int loMax = 0, hiMax = 0;
    int water = 0;

    while (lo < hi)
    {
        if (height[lo] < height[hi])
        {
            if (height[lo] >= loMax)
                loMax = height[lo];
            else
                water += loMax - height[lo];
            lo++;
        }
        else
        {
            if (height[hi] >= hiMax)
                hiMax = height[hi];
            else
                water += hiMax - height[hi];
            hi--;
        }
    }
    return water;
}

int main(void)
{
    int h1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int h2[] = {4, 2, 0, 3, 2, 5};

    printf("%d\n", trap(h1, 12)); /* 6 */
    printf("%d\n", trap(h2, 6));  /* 9 */
    return 0;
}