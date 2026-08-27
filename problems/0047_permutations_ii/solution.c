/*
 * Permutations II (LeetCode #47, Medium)
 *
 * Same swap-based backtracking as #46, but input may contain
 * duplicates. To avoid generating duplicate permutations we sort
 * the array first, then skip an element if it's identical to the
 * previous one AND we're at the same recursion depth (i > start
 * && nums[i] == nums[i-1]). The swap trick still works because
 * we only swap each unique element into the current position.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void backtrack(int *nums, int n, int start,
                      int **res, int *cols, int *count)
{
    if (start == n)
    {
        int *perm = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            perm[i] = nums[i];
        res[*count] = perm;
        cols[*count] = n;
        (*count)++;
        return;
    }

    for (int i = start; i < n; i++)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;               /* skip duplicate at this depth */
        swap(&nums[start], &nums[i]);
        backtrack(nums, n, start + 1, res, cols, count);
        swap(&nums[start], &nums[i]); /* restore */
    }
}

/* LeetCode solution. Returns all unique permutations. */
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp_int);

    int fact = 1;
    for (int i = 2; i <= numsSize; i++)
        fact *= i;

    int **res = (int **)malloc(fact * sizeof(int *));
    int *cols = (int *)malloc(fact * sizeof(int));
    int count = 0;

    backtrack(nums, numsSize, 0, res, cols, &count);

    *returnSize = count;
    *returnColumnSizes = cols;
    return res;
}

static void print_perms(int **res, int count, int *cols)
{
    printf("%d unique permutation(s):\n", count);
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
    int n1[] = {1, 1, 2};
    int sz1, *cols1;
    int **r1 = permuteUnique(n1, 3, &sz1, &cols1);
    printf("[1,1,2]\n");
    print_perms(r1, sz1, cols1);

    int n2[] = {1, 2, 3};
    int sz2, *cols2;
    int **r2 = permuteUnique(n2, 3, &sz2, &cols2);
    printf("[1,2,3]\n");
    print_perms(r2, sz2, cols2);
    return 0;
}