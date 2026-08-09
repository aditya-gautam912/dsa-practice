/*
 * LeetCode #34: Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 *
 * Human approach:
 * Binary search already finds *a* match, but we need the first AND last.
 * Trick: run binary search twice. Once, when we hit target we keep going
 * left to find the very first match. Then again, keep going right to find
 * the very last match. Combine both answers.
 */

#include <stdio.h>

static int findBound(int *nums, int numsSize, int target, int wantLeft)
{
    int low = 0, high = numsSize - 1;
    int bound = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            bound = mid;
            if (wantLeft)
                high = mid - 1; /* squeeze to the left */
            else
                low = mid + 1;  /* squeeze to the right */
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return bound;
}

/* LeetCode solution. The first index goes to leftBound index 0,
   the last index goes to rightBound index 1. */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = findBound(nums, numsSize, target, 1);
    result[1] = findBound(nums, numsSize, target, 0);
    return result;
}

int main(void)
{
    int n[] = {5, 7, 7, 8, 8, 10};
    int retSize;
    int *res = searchRange(n, 6, 8, &retSize);
    printf("Test 1: [%d, %d]\n", res[0], res[1]);
    free(res);

    res = searchRange(n, 6, 6, &retSize);
    printf("Test 2: [%d, %d]\n", res[0], res[1]);
    free(res);
    return 0;
}