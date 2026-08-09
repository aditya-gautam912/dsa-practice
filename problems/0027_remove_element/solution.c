/*
 * LeetCode #27: Remove Element
 * Difficulty: Easy
 *
 * Human approach:
 * Walk through the array with one "write" pointer. Every number that is
 * not the value we want to remove gets copied forward. The numbers we
 * want to remove are skipped and effectively discarded.
 */

#include <stdio.h>

/* LeetCode solution. Returns how many elements are left after removal. */
int removeElement(int *nums, int numsSize, int val)
{
    int write = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[write] = nums[i];
            write++;
        }
    }
    return write;
}

int main(void)
{
    int n1[] = {3, 2, 2, 3};
    int n2[] = {0, 1, 2, 2, 3, 0, 4, 2};

    int k1 = removeElement(n1, 4, 3);
    printf("Test 1: k = %d -> ", k1);
    for (int i = 0; i < k1; i++)
        printf("%d ", n1[i]);
    printf("\n");

    int k2 = removeElement(n2, 8, 2);
    printf("Test 2: k = %d -> ", k2);
    for (int i = 0; i < k2; i++)
        printf("%d ", n2[i]);
    printf("\n");

    return 0;
}