/*
 * Two Sum (LeetCode #1, Easy)
 *
 * Classic one. First one I ever solved properly.
 * Brute force is O(n^2) — for every pair just add and compare.
 * The hash map idea is what everyone wants: walk through the array
 * once, and for each number ask "do I already have (target - this)?".
 * If yes, we're done. Otherwise remember this number's index.
 */

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    /* keep it simple: store what we've seen so far */
    int *seenVals = (int *)malloc(numsSize * sizeof(int));
    int *seenIdx = (int *)malloc(numsSize * sizeof(int));
    int seenCount = 0;

    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        /* linear scan into our little map - n is small, fine for demo */
        for (int j = 0; j < seenCount; j++)
        {
            if (seenVals[j] == complement)
            {
                result[0] = seenIdx[j];
                result[1] = i;
                *returnSize = 2;
                free(seenVals);
                free(seenIdx);
                return result;
            }
        }
        seenVals[seenCount] = nums[i];
        seenIdx[seenCount] = i;
        seenCount++;
    }

    free(seenVals);
    free(seenIdx);
    free(result);
    return NULL;
}

int main(void)
{
    int nums1[] = {2, 7, 11, 15};
    int nums2[] = {3, 2, 4};
    int nums3[] = {3, 3};
    int retSize;
    int *res;

    res = twoSum(nums1, 4, 9, &retSize);
    if (retSize == 2)
        printf("{%d, %d}\n", res[0], res[1]); /* expect {0,1} */
    free(res);

    res = twoSum(nums2, 3, 6, &retSize);
    if (retSize == 2)
        printf("{%d, %d}\n", res[0], res[1]); /* expect {1,2} */
    free(res);

    res = twoSum(nums3, 2, 6, &retSize);
    if (retSize == 2)
        printf("{%d, %d}\n", res[0], res[1]); /* expect {0,1} */
    free(res);

    return 0;
}