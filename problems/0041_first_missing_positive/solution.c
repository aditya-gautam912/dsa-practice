/*
 * LeetCode #41: First Missing Positive
 * Difficulty: Hard
 *
 * Human approach:
 * We want the smallest positive number that is missing. If 1 is present,
 * place it at index 0; if 2 is present, put it at index 1 and so on.
 * This "sorting in place" puts every number x (between 1 and n) at index
 * x-1. After that, the first spot where our number does not match gives
 * the answer.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* LeetCode solution. */
int firstMissingPositive(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] >= 1 && nums[i] <= numsSize &&
               nums[nums[i] - 1] != nums[i])
        {
            swap(&nums[nums[i] - 1], &nums[i]);
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return numsSize + 1;
}

int main(void)
{
    int n1[] = {1, 2, 0};
    int n2[] = {3, 4, -1, 1};
    int n3[] = {7, 8, 9, 11, 12};

    printf("Test 1: %d\n", firstMissingPositive(n1, 3));   /* 3 */
    printf("Test 2: %d\n", firstMissingPositive(n2, 4));   /* 2 */
    printf("Test 3: %d\n", firstMissingPositive(n3, 5));   /* 1 */
    return 0;
}