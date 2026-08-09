/*
 * LeetCode #1: Two Sum
 * Difficulty: Easy
 *
 * Human approach:
 * We need to find two numbers that add up to target.
 * Think of it like this: for each number, we ask "does the
 * number we need (target - current) already exist?".
 * Instead of scanning again for every number (slow), we
 * remember each number and its position as we go. That way
 * the answer is found in one quick pass.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode solution:
 * Returns an array of 2 indices whose values add up to target.
 * *returnSize must be set to 2.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    /* MAP: we store previously seen values in two arrays
       (a poor-man's hash map for demonstration simplicity). */
    int *seenVals = (int *)malloc(numsSize * sizeof(int));
    int *seenIdx = (int *)malloc(numsSize * sizeof(int));
    int seenCount = 0;

    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
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

/* Simple manual test harness (human-style verification) */
int main(void)
{
    int nums1[] = {2, 7, 11, 15};
    int nums2[] = {3, 2, 4};
    int nums3[] = {3, 3};
    int retSize;
    int *res;

    res = twoSum(nums1, 4, 9, &retSize);
    if (retSize == 2)
        printf("Test 1: [%d, %d]\n", res[0], res[1]);
    free(res);

    res = twoSum(nums2, 3, 6, &retSize);
    if (retSize == 2)
        printf("Test 2: [%d, %d]\n", res[0], res[1]);
    free(res);

    res = twoSum(nums3, 2, 6, &retSize);
    if (retSize == 2)
        printf("Test 3: [%d, %d]\n", res[0], res[1]);
    free(res);

    return 0;
}