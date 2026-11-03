/*
 * Single Number (LeetCode #136, Easy)
 *
 * Using the XOR bitwise operator to cancel out pairs.
 * The remaining value is the single number.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns the single number in the array. */
int singleNumber(int *nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0)
        return 0;

    int result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }

    return result;
}

int main(void)
{
    int nums1[] = {2, 2, 1};
    printf("[2,2,1] -> %d (expected 1)\n", singleNumber(nums1, 3));

    int nums2[] = {4, 1, 2, 1, 2};
    printf("[4,1,2,1,2] -> %d (expected 4)\n", singleNumber(nums2, 5));

    return 0;
}
