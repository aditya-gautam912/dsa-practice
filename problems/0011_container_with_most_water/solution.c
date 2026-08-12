/*
 * Container With Most Water (LeetCode #11, Medium)
 *
 * Two pointers from both ends. Water = shorter wall * gap.
 * Why move the shorter side? Because the short wall is the one
 * capping the water - moving the taller one can only shrink the gap
 * without any hope of a taller limiting wall. Obvious once you
 * think about it, but tripped me up on my first attempt.
 */

#include <stdio.h>

int maxArea(int *height, int heightSize)
{
    int lo = 0, hi = heightSize - 1;
    int best = 0;

    while (lo < hi)
    {
        int h = height[lo] < height[hi] ? height[lo] : height[hi];
        int water = h * (hi - lo);
        if (water > best)
            best = water;

        if (height[lo] < height[hi])
            lo++;
        else
            hi--;
    }
    return best;
}

int main(void)
{
    int h1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int h2[] = {1, 1};

    printf("%d (want 49)\n", maxArea(h1, 9));
    printf("%d (want 1)\n", maxArea(h2, 2));
    return 0;
}