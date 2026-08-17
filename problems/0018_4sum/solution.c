/*
 * 4Sum (LeetCode #18, Medium)
 *
 * Same idea as 3Sum, one level deeper: fix the first two numbers,
 * then use the classic two-pointer sweep on the rest. Sorting the
 * array makes skipping duplicates easy, and the two-pointer trick
 * keeps the innermost loop linear instead of quadratic.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

/* LeetCode solution. Returns all unique quadruplets that sum to
 * target. *returnSize = number of quadruplets. */
int **fourSum(int *nums, int numsSize, int target, int *returnSize,
              int **returnColumnSizes)
{
    int **res = (int **)malloc(numsSize * numsSize * sizeof(int *));
    int count = 0;

    qsort(nums, numsSize, sizeof(int), cmp_int);

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; /* skip duplicate first numbers */
        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue; /* skip duplicate second numbers */

            int left = j + 1, right = numsSize - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] +
                                nums[left] + nums[right];
                if (sum == target)
                {
                    int *quad = (int *)malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    res[count++] = quad;

                    /* skip duplicates on both pointers */
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    *returnSize = count;
    int *cols = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        cols[i] = 4;
    *returnColumnSizes = cols;
    return res;
}

static void print_result(int **res, int count, int *cols)
{
    printf("%d quadruplet(s):\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("[");
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d", res[i][j]);
            if (j + 1 < cols[i])
                printf(", ");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(cols);
}

int main(void)
{
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int size1, *cols1;
    int **r1 = fourSum(nums1, 6, 0, &size1, &cols1);
    printf("nums=[1,0,-1,0,-2,2], target=0\n");
    print_result(r1, size1, cols1);

    int nums2[] = {2, 2, 2, 2, 2};
    int size2, *cols2;
    int **r2 = fourSum(nums2, 5, 8, &size2, &cols2);
    printf("nums=[2,2,2,2,2], target=8\n");
    print_result(r2, size2, cols2);
    return 0;
}