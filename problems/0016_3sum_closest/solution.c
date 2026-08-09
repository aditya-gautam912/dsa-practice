/*
 * LeetCode #16: 3Sum Closest
 * Difficulty: Medium
 *
 * Human approach:
 * Same trick as 3Sum: sort and fix one number, then use two pointers.
 * Instead of looking for an exact zero sum, we keep track of the sum
 * that is closest to the target so far, updating it whenever we find
 * something nearer.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. */
int threeSumClosest(int *nums, int numsSize, int target);

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++)
    {
        int left = i + 1, right = numsSize - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target))
                closest = sum;

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return sum; /* exact match cannot be beaten */
        }
    }
    return closest;
}

int main(void)
{
    int n1[] = {-1, 2, 1, -4};
    int n2[] = {0, 0, 0};
    int n3[] = {1, 1, 1, 0};

    printf("Test 1: %d\n", threeSumClosest(n1, 4, 1));  /* 2 */
    printf("Test 2: %d\n", threeSumClosest(n2, 3, 1));  /* 0 */
    printf("Test 3: %d\n", threeSumClosest(n3, 4, -100)); /* 2 */
    return 0;
}