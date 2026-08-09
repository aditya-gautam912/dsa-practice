/*
 * LeetCode #26: Remove Duplicates from Sorted Array
 * Difficulty: Easy
 *
 * Human approach:
 * The array is already sorted, so equal values sit next to each other.
 * We keep one "write" pointer. Walk through the array; whenever we see
 * a new number (different from the previous), we write it at the write
 * pointer and move it forward. Everything in front is the unique list.
 */

#include <stdio.h>

/* LeetCode solution: returns the count of unique elements. */
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int write = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[write] = nums[i];
            write++;
        }
    }
    return write;
}

int main(void)
{
    int a[] = {1, 1, 2};
    int b[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k1 = removeDuplicates(a, 3);
    printf("Test 1: k=%d ", k1);
    for (int i = 0; i < k1; i++)
        printf("%d ", a[i]);
    printf("\n");

    int k2 = removeDuplicates(b, 10);
    printf("Test 2: k=%d ", k2);
    for (int i = 0; i < k2; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}