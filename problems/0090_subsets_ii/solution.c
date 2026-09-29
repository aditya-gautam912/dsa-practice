/*
 * Subsets II (LeetCode #90, Medium)
 *
 * Same backtracking as Subsets (#78), but the input may
 * contain duplicates. Sort the array first, then skip an
 * element if it equals the previous one AND we're at the
 * same recursion depth (i > start && nums[i] == nums[i-1]).
 * This prevents generating duplicate subsets.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

static void backtrack(int *nums, int n, int start,
                       int *path, int pathLen,
                       int **res, int *cols, int *count)
{
    int *combo = (int *)malloc(pathLen * sizeof(int));
    for (int i = 0; i < pathLen; i++)
        combo[i] = path[i];
    res[*count] = combo;
    cols[*count] = pathLen;
    (*count)++;

    for (int i = start; i < n; i++)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;               /* skip duplicate at this depth */
        path[pathLen] = nums[i];
        backtrack(nums, n, i + 1, path, pathLen + 1,
                  res, cols, count);
    }
}

/* LeetCode solution. Returns all unique subsets. */
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp_int);

    int maxCombos = 1 << numsSize;
    int **res = (int **)malloc(maxCombos * sizeof(int *));
    int *cols = (int *)malloc(maxCombos * sizeof(int));
    int path[16];
    int count = 0;

    backtrack(nums, numsSize, 0, path, 0, res, cols, &count);

    *returnSize = count;
    *returnColumnSizes = cols;
    return res;
}

static void print_subsets(int **res, int count, int *cols)
{
    printf("%d subset(s):\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("[");
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d", res[i][j]);
            if (j + 1 < cols[i])
                printf(",");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(cols);
}

int main(void)
{
    int n1[] = {1, 2, 2};
    int sz1, *cols1;
    int **r1 = subsetsWithDup(n1, 3, &sz1, &cols1);
    printf("[1,2,2] -> ");
    print_subsets(r1, sz1, cols1);

    int n2[] = {0};
    int sz2, *cols2;
    int **r2 = subsetsWithDup(n2, 1, &sz2, &cols2);
    printf("[0] -> ");
    print_subsets(r2, sz2, cols2);
    return 0;
}