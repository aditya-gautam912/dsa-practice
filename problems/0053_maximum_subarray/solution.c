/*
 * Maximum Subarray (LeetCode #53, Easy)
 *
 * Kadane's algorithm, as simple as it gets: carry a running sum.
 * If extending the current subarray makes things worse than just
 * starting over, start over. Keep the best seen. That's the whole
 * thing - the moment this "clicked" for me was when I stopped
 * thinking of subarrays as something to search and started
 * thinking "just keep going until it hurts."
 */

#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
    int running = 0;
    int best = nums[0];

    for (int i = 0; i < numsSize; i++)
    {
        if (running + nums[i] > nums[i])
            running += nums[i];
        else
            running = nums[i];

        if (running > best)
            best = running;
    }
    return best;
}

int main(void)
{
    int n1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n2[] = {1};
    int n3[] = {5, 4, -1, 7, 8};

    printf("%d\n", maxSubArray(n1, 9)); /* 6 */
    printf("%d\n", maxSubArray(n2, 1)); /* 1 */
    printf("%d\n", maxSubArray(n3, 5)); /* 23 */
    return 0;
}