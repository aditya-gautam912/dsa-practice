/*
 * Find First and Last Position (LeetCode #34, Medium)
 *
 * Plain binary search finds A match, but we want the edges.
 * Solution: run binary search twice. First pass, when we hit the
 * target we keep squeezing left to find the earliest one. Second
 * pass squeezes right for the latest. Two helpers, one flag.
 */

#include <stdio.h>
#include <stdlib.h>

static int findBound(int *nums, int numsSize, int target, int wantLeft)
{
    int lo = 0, hi = numsSize - 1;
    int bound = -1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
        {
            bound = mid;
            if (wantLeft)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return bound;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *res = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    res[0] = findBound(nums, numsSize, target, 1);
    res[1] = findBound(nums, numsSize, target, 0);
    return res;
}

int main(void)
{
    int n[] = {5, 7, 7, 8, 8, 10};
    int retSize;
    int *res;

    res = searchRange(n, 6, 8, &retSize);
    printf("[%d, %d]\n", res[0], res[1]); /* want [3,4] */
    free(res);

    res = searchRange(n, 6, 6, &retSize);
    printf("[%d, %d]\n", res[0], res[1]); /* want [-1,-1] */
    free(res);
    return 0;
}