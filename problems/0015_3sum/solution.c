/*
 * 3Sum (LeetCode #15, Medium)
 *
 * The two-sum-inside-a-loop pattern. Sort first: then duplicates
 * are easy to skip and the two-pointer pass does the heavy lifting.
 * The dedup part was where I kept messing up - easy to forget you
 * must skip repeats on left AND right after a match.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y); /* avoids overflow on big ints */
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int **res = (int **)malloc(numsSize * numsSize * sizeof(int *));
    int *cols = (int *)malloc(numsSize * numsSize * sizeof(int));
    int n = 0;

    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; /* same "first" value -> same triplets */

        int lo = i + 1, hi = numsSize - 1;
        while (lo < hi)
        {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == 0)
            {
                int *t = (int *)malloc(3 * sizeof(int));
                t[0] = nums[i];
                t[1] = nums[lo];
                t[2] = nums[hi];
                res[n] = t;
                cols[n] = 3;
                n++;
                lo++;
                hi--;
                while (lo < hi && nums[lo] == nums[lo - 1])
                    lo++;
                while (lo < hi && nums[hi] == nums[hi + 1])
                    hi--;
            }
            else if (sum < 0)
                lo++;
            else
                hi--;
        }
    }

    *returnSize = n;
    *returnColumnSizes = cols;
    return res;
}

int main(void)
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int m, *cols;
    int **res = threeSum(nums, 6, &m, &cols);

    for (int i = 0; i < m; i++)
    {
        printf("[%d, %d, %d]\n", res[i][0], res[i][1], res[i][2]);
        free(res[i]);
    }
    free(res);
    free(cols);
    return 0;
}