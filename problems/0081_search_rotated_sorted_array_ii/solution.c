/*
 * Search in Rotated Sorted Array II (LeetCode #81, Medium)
 *
 * Follow-up to #33: duplicates are now allowed. This makes
 * the worst case ambiguous — when nums[left] == nums[mid]
 * == nums[right], neither half is guaranteed sorted. In that
 * case we shrink both ends by one and continue the search.
 * Otherwise we determine which half is sorted and binary
 * search within it.
 */

#include <stdbool.h>
#include <stdio.h>

/* LeetCode solution. Returns true if target is found. */
bool search(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;

        /* ambiguous: shrink both ends */
        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
        }
        /* left half is sorted */
        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        /* right half is sorted */
        else
        {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

int main(void)
{
    int n1[] = {2, 5, 6, 0, 0, 1, 2};
    printf("[2,5,6,0,0,1,2], target=0 -> %s (expected true)\n",
           search(n1, 7, 0) ? "true" : "false");
    printf("[2,5,6,0,0,1,2], target=3 -> %s (expected false)\n",
           search(n1, 7, 3) ? "true" : "false");

    int n2[] = {1};
    printf("[1], target=0 -> %s (expected false)\n",
           search(n2, 1, 0) ? "true" : "false");
    return 0;
}