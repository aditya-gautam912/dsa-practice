/*
 * Remove Element (LeetCode #27, Easy)
 *
 * Same "write pointer" idea as #26. Anything that isn't val gets
 * shifted left. Values we keep don't shift back, so we can overwrite
 * the removed ones - order of surviving elements is preserved too.
 */

#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int write = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] != val)
            nums[write++] = nums[i];

    return write;
}

int main(void)
{
    int n1[] = {3, 2, 2, 3};
    int n2[] = {0, 1, 2, 2, 3, 0, 4, 2};

    int k1 = removeElement(n1, 4, 3);
    printf("k = %d: ", k1);
    for (int i = 0; i < k1; i++)
        printf("%d ", n1[i]);
    printf("\n");

    int k2 = removeElement(n2, 8, 2);
    printf("k = %d: ", k2);
    for (int i = 0; i < k2; i++)
        printf("%d ", n2[i]);
    printf("\n");

    return 0;
}