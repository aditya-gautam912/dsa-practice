/*
 * LeetCode #33: Search in Rotated Sorted Array
 * Difficulty: Medium
 *
 * Human approach:
 * One side of the rotation is always sorted. At each step we check which
 * half is sorted by comparing the middle with the left end. If the target
 * fits inside that sorted half, we search there; otherwise we go to the
 * other half. This keeps things just as fast as normal binary search.
 */

#include <stdio.h>

/* LeetCode solution. Returns the index of target or -1. */
int search(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid]) /* left half is sorted */
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else /* right half is sorted */
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int n1[] = {4, 5, 6, 7, 0, 1, 2};
    int n2[] = {4, 5, 6, 7, 0, 1, 2};
    printf("Test 1: %d\n", search(n1, 7, 0)); /* 4 */
    printf("Test 2: %d\n", search(n2, 7, 3)); /* -1 */
    return 0;
}