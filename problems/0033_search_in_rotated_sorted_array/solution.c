/*
 * Search in Rotated Sorted Array (LeetCode #33, Medium)
 *
 * Key insight: even when rotated, one half is always fully sorted.
 * Check which half and whether target lives there, then just do a
 * normal binary search but narrowed to the useful half. The original
 * array being rotated always gives us a sorted segment to lean on.
 */

#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int lo = 0, hi = numsSize - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[lo] <= nums[mid]) /* left half sorted */
        {
            if (nums[lo] <= target && target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else /* right half sorted */
        {
            if (nums[mid] < target && target <= nums[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int n1[] = {4, 5, 6, 7, 0, 1, 2};
    int n2[] = {4, 5, 6, 7, 0, 1, 2};

    printf("%d (want 4)\n", search(n1, 7, 0));
    printf("%d (want -1)\n", search(n2, 7, 3));
    return 0;
}