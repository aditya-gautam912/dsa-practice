/*
 * Search Insert Position (LeetCode #35, Easy)
 *
 * Yet another binary search. Handy property: when the target
 * doesn't exist, "lo" ends up exactly at the insertion spot.
 * So there's nothing special to handle - just return lo.
 */

#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int lo = 0, hi = numsSize - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int main(void)
{
    int n[] = {1, 3, 5, 6};

    printf("%d\n", searchInsert(n, 4, 5)); /* 2 */
    printf("%d\n", searchInsert(n, 4, 2)); /* 1 */
    printf("%d\n", searchInsert(n, 4, 7)); /* 4 */
    return 0;
}