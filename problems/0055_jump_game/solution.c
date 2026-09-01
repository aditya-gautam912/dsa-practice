/*
 * Jump Game (LeetCode #55, Medium)
 *
 * Greedy: track the farthest index reachable so far.
 * Walk the array; if the current index ever exceeds the
 * farthest reachable, we are stuck (return false). If the
 * farthest reaches or passes the last index, return true.
 * Single pass, O(1) space.
 */

#include <stdbool.h>
#include <stdio.h>

/* LeetCode solution. Returns true if you can reach the last index. */
bool canJump(int *nums, int numsSize)
{
    int farthest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i > farthest)
            return false;     /* stuck */
        if (farthest >= numsSize - 1)
            return true;      /* can already reach end */
        farthest = farthest > i + nums[i] ? farthest : i + nums[i];
    }
    return true;
}

int main(void)
{
    int n1[] = {2, 3, 1, 1, 4};
    printf("[2,3,1,1,4] -> %s (expected true)\n", canJump(n1, 5) ? "true" : "false");

    int n2[] = {3, 2, 1, 0, 4};
    printf("[3,2,1,0,4] -> %s (expected false)\n", canJump(n2, 5) ? "true" : "false");

    int n3[] = {0};
    printf("[0]        -> %s (expected true)\n", canJump(n3, 1) ? "true" : "false");
    return 0;
}