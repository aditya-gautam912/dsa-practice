/*
 * Single Number II (LeetCode #137, Medium)
 *
 * Every number appears three times except one. Count each bit
 * across all numbers; bits whose count is not divisible by three
 * belong to the answer. Treating the values as unsigned while
 * shifting keeps the sign bit well-defined.
 */

#include <stdio.h>

/* LeetCode solution. Returns the element that appears once. */
int singleNumber(int *nums, int numsSize)
{
    unsigned int answer = 0;

    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;
        unsigned int mask = 1u << bit;

        for (int i = 0; i < numsSize; i++)
            if ((unsigned int)nums[i] & mask)
                count++;

        if (count % 3 != 0)
            answer |= mask;
    }
    return (int)answer;
}

int main(void)
{
    int nums1[] = {2, 2, 3, 2};
    printf("[2,2,3,2] -> %d (expected 3)\n", singleNumber(nums1, 4));

    int nums2[] = {0, 1, 0, 1, 0, 1, 99};
    printf("[0,1,0,1,0,1,99] -> %d (expected 99)\n",
           singleNumber(nums2, 7));

    int nums3[] = {-2, -2, -2, -7};
    printf("[-2,-2,-2,-7] -> %d (expected -7)\n",
           singleNumber(nums3, 4));
    return 0;
}
