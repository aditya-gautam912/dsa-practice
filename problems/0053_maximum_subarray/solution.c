/*
 * LeetCode #53: Maximum Subarray
 * Difficulty: Easy
 *
 * Human approach:
 * Walk through the array and keep a running sum. If adding the current
 * number makes the running sum smaller than just the number itself, it is
 * better to start a fresh subarray here. Always remember the best sum we
 * have seen. That is Kadane's algorithm in one sentence.
 */

#include <stdio.h>

/* LeetCode solution. */
int maxSubArray(int *nums, int numsSize)
{
    int currentSum = 0;
    int best = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];

        if (currentSum > best)
            best = currentSum;
    }
    return best;
}

int main(void)
{
    int n1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n2[] = {1};
    int n3[] = {5, 4, -1, 7, 8};

    printf("Test 1: %d\n", maxSubArray(n1, 9));  /* 6 */
    printf("Test 2: %d\n", maxSubArray(n2, 1));  /* 1 */
    printf("Test 3: %d\n", maxSubArray(n3, 5));  /* 23 */
    return 0;
}