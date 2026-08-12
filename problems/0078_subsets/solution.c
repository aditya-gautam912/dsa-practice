/*
 * Subsets (LeetCode #78, Medium)
 *
 * All subsets of a set of unique numbers. Classic backtracking:
 * for each number, either take it or don't. The recursive pattern
 * is the same as generating all binary strings of length n.
 * Iterative version is also clean: start with empty set, for each
 * number double the current collection by appending the new element
 * to every existing subset.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution.
 * Returns a dynamically allocated array of subsets.
 * *returnSize = number of subsets (2^n).
 * *returnColumnSizes points to an array of each subset's size.
 */
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int total = 1 << numsSize;          /* 2^n subsets */
    int **res = (int **)malloc(total * sizeof(int *));
    int *cols = (int *)malloc(total * sizeof(int));

    for (int mask = 0; mask < total; mask++)
    {
        int count = 0;
        int *subset = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++)
            if (mask & (1 << i))
                subset[count++] = nums[i];
        res[mask] = subset;
        cols[mask] = count;
    }

    *returnSize = total;
    *returnColumnSizes = cols;
    return res;
}

int main(void)
{
    int nums[] = {1, 2, 3};
    int n = 3, retSize, *cols;
    int **res = subsets(nums, n, &retSize, &cols);

    printf("%d subsets:\n", retSize);
    for (int i = 0; i < retSize; i++)
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
    return 0;
}