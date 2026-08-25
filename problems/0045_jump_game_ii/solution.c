/*
 * Jump Game II (LeetCode #45, Medium)
 *
 * Greedy: at each step keep track of the farthest index reachable
 * within the current number of jumps. When we exhaust the current
 * reach, we must make another jump and update the reach to the
 * best we've seen so far. Single pass, O(1) space.
 */

#include <stdio.h>

/* LeetCode solution. Returns minimum number of jumps to reach end. */
int jump(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return 0;

    int jumps = 0;
    int currentEnd = 0;   /* farthest index reachable with current jumps */
    int farthest = 0;     /* farthest index reachable with one more jump */

    for (int i = 0; i < numsSize - 1; i++)
    {
        farthest = farthest > i + nums[i] ? farthest : i + nums[i];
        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;
            if (currentEnd >= numsSize - 1)
                break;
        }
    }
    return jumps;
}

int main(void)
{
    int n1[] = {2, 3, 1, 1, 4};
    printf("[2,3,1,1,4] -> %d (expected 2)\n", jump(n1, 5));

    int n2[] = {2, 3, 0, 1, 4};
    printf("[2,3,0,1,4] -> %d (expected 2)\n", jump(n2, 5));

    int n3[] = {1, 2, 3};
    printf("[1,2,3]     -> %d (expected 2)\n", jump(n3, 3));
    return 0;
}