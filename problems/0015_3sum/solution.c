/*
 * LeetCode #15: 3Sum
 * Difficulty: Medium
 *
 * Human approach:
 * To find three numbers that sum to zero, first sort the array.
 * Then fix one number. For the remaining pair, use two pointers from
 * both ends. If the sum is too small, bring the left pointer up; if too
 * large, bring the right pointer down. Skip repeated numbers so we don't
 * return the same triplet twice.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

/* LeetCode solution.
   Returns a dynamically allocated array of triplets.
   The caller is responsible for freeing. */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int **result = (int **)malloc(numsSize * numsSize * sizeof(int *));
    int *cols = (int *)malloc(numsSize * numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = numsSize - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                result[count] = triplet;
                cols[count] = 3;
                count++;
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    *returnSize = count;
    *returnColumnSizes = cols;
    return result;
}

int main(void)
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize, *cols;
    int **res = threeSum(nums, 6, &returnSize, &cols);

    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d, %d, %d]\n", res[i][0], res[i][1], res[i][2]);
        free(res[i]);
    }
    free(res);
    free(cols);
    return 0;
}