/*
 * 3Sum Closest (LeetCode #16, Medium)
 *
 * Same as 3Sum but instead of zero we chase a target.
 * Sort, fix one, two-pointer the rest, keep the best difference.
 * If you land exactly on target, bail early - nothing gets closer.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int best = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++)
    {
        int lo = i + 1, hi = numsSize - 1;
        while (lo < hi)
        {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (abs(sum - target) < abs(best - target))
                best = sum;

            if (sum < target)
                lo++;
            else if (sum > target)
                hi--;
            else
                return sum; /* exact -- cannot beat 0 difference */
        }
    }
    return best;
}

int main(void)
{
    int n1[] = {-1, 2, 1, -4};
    int n2[] = {0, 0, 0};
    int n3[] = {1, 1, 1, 0};

    printf("%d (want 2)\n", threeSumClosest(n1, 4, 1));
    printf("%d (want 0)\n", threeSumClosest(n2, 3, 1));
    printf("%d (want 2)\n", threeSumClosest(n3, 4, -100));
    return 0;
}