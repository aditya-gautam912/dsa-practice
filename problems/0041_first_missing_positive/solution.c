/*
 * First Missing Positive (LeetCode #41, Hard)
 *
 * The "aha" here: for a positive x in 1..n, its home is index x-1.
 * We shuffle numbers into their homes with swaps. After that the
 * array is scrambled but the first index where nums[i] != i+1
 * tells us exactly which positive is missing. O(n) time while
 * doing it with zero extra memory. Took me a while to trust swaps
 * instead of worrying about temporary values.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int firstMissingPositive(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        /* keep swapping until the number is home, out of range, or dup */
        while (nums[i] >= 1 && nums[i] <= numsSize &&
               nums[nums[i] - 1] != nums[i])
        {
            swap(&nums[nums[i] - 1], &nums[i]);
        }
    }

    for (int i = 0; i < numsSize; i++)
        if (nums[i] != i + 1)
            return i + 1;

    return numsSize + 1;
}

int main(void)
{
    int n1[] = {1, 2, 0};
    int n2[] = {3, 4, -1, 1};
    int n3[] = {7, 8, 9, 11, 12};

    printf("%d\n", firstMissingPositive(n1, 3)); /* 3 */
    printf("%d\n", firstMissingPositive(n2, 4)); /* 2 */
    printf("%d\n", firstMissingPositive(n3, 5)); /* 1 */
    return 0;
}