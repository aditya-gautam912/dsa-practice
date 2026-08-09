/*
 * LeetCode #35: Search Insert Position
 * Difficulty: Easy
 *
 * Human approach:
 * Plain binary search. When the target exists we return its index.
 * When it does not exist, the left pointer naturally lands exactly where
 * the target should be inserted, so we return that value.
 */

#include <stdio.h>

/* LeetCode solution. */
int searchInsert(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main(void)
{
    int n[] = {1, 3, 5, 6};
    printf("Test 1: %d\n", searchInsert(n, 4, 5)); /* 2 */
    printf("Test 2: %d\n", searchInsert(n, 4, 2)); /* 1 */
    printf("Test 3: %d\n", searchInsert(n, 4, 7)); /* 4 */
    return 0;
}