/*
 * Remove Duplicates from Sorted Array II (LeetCode #80, Medium)
 *
 * Each unique element may appear at most twice. Two-pointer:
 * k is the write position. For every element at index i,
 * if k < 2 or nums[i] > nums[k-2] (meaning we haven't used
 * this value twice already), we keep it by writing to nums[k].
 * Single pass, O(1) extra space.
 */

#include <stdio.h>

/* LeetCode solution. Returns k — the length of the
 * modified array with each element appearing at most twice. */
int removeDuplicates(int *nums, int numsSize)
{
    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (k < 2 || nums[i] > nums[k - 2])
            nums[k++] = nums[i];
    }
    return k;
}

int main(void)
{
    int n1[] = {1, 1, 1, 2, 2, 3};
    int k1 = removeDuplicates(n1, 6);
    printf("[1,1,1,2,2,3] -> k=%d: [", k1);
    for (int i = 0; i < k1; i++)
        printf("%d%c", n1[i], i + 1 < k1 ? ',' : '\0');
    printf("] (expected k=5)\n");

    int n2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = removeDuplicates(n2, 9);
    printf("[0,0,1,1,1,1,2,3,3] -> k=%d: [", k2);
    for (int i = 0; i < k2; i++)
        printf("%d%c", n2[i], i + 1 < k2 ? ',' : '\0');
    printf("] (expected k=7)\n");
    return 0;
}