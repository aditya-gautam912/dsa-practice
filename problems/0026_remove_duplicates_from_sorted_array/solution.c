/*
 * Remove Duplicates from Sorted Array (LeetCode #26, Easy)
 *
 * Since it's sorted, duplicates are neighbours. One pointer writes,
 * the other reads. Whenever the reader sees a different value,
 * the writer copies it forward. That's the whole trick - any
 * "in-place array rewrite" is basically this pattern.
 */

#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int write = 1;
    for (int i = 1; i < numsSize; i++)
        if (nums[i] != nums[i - 1])
            nums[write++] = nums[i];

    return write;
}

int main(void)
{
    int a[] = {1, 1, 2};
    int b[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k1 = removeDuplicates(a, 3);
    printf("k = %d: ", k1);
    for (int i = 0; i < k1; i++)
        printf("%d ", a[i]);
    printf("\n");

    int k2 = removeDuplicates(b, 10);
    printf("k = %d: ", k2);
    for (int i = 0; i < k2; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}