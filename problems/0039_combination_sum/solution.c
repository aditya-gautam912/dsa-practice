/*
 * Combination Sum (LeetCode #39, Medium)
 *
 * Classic backtracking: sort candidates, then for each index we may
 * either take that candidate (and stay at the same index because
 * unlimited reuse is allowed) or skip to the next one. Whenever
 * the running sum equals the target, we record the current path.
 * Sorting also lets us prune early when the sum overshoots.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

static void backtrack(int *c, int n, int target, int start,
                      int *path, int pathLen,
                      int **res, int *cols, int *count)
{
    if (target == 0)
    {
        int *combo = (int *)malloc(pathLen * sizeof(int));
        for (int i = 0; i < pathLen; i++)
            combo[i] = path[i];
        res[*count] = combo;
        cols[*count] = pathLen;
        (*count)++;
        return;
    }

    for (int i = start; i < n; i++)
    {
        if (c[i] > target)
            break;                  /* sorted → no need to continue */
        path[pathLen] = c[i];
        backtrack(c, n, target - c[i], i, path, pathLen + 1,
                  res, cols, count);
    }
}

/* LeetCode solution. Returns all unique combinations that sum to target. */
int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), cmp_int);

    int maxCombos = 1000;           /* safe upper bound for target ≤ 500 */
    int **res = (int **)malloc(maxCombos * sizeof(int *));
    int *cols = (int *)malloc(maxCombos * sizeof(int));
    int path[50];
    int count = 0;

    backtrack(candidates, candidatesSize, target, 0, path, 0,
              res, cols, &count);

    *returnSize = count;
    *returnColumnSizes = cols;
    return res;
}

static void print_combos(int **res, int count, int *cols)
{
    printf("%d combination(s):\n", count);
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
    int c1[] = {2, 3, 6, 7};
    int sz1, *cols1;
    int **r1 = combinationSum(c1, 4, 7, &sz1, &cols1);
    printf("candidates=[2,3,6,7], target=7\n");
    print_combos(r1, sz1, cols1);

    int c2[] = {2, 3, 5};
    int sz2, *cols2;
    int **r2 = combinationSum(c2, 3, 8, &sz2, &cols2);
    printf("candidates=[2,3,5], target=8\n");
    print_combos(r2, sz2, cols2);

    int c3[] = {2};
    int sz3, *cols3;
    int **r3 = combinationSum(c3, 1, 1, &sz3, &cols3);
    printf("candidates=[2], target=1\n");
    print_combos(r3, sz3, cols3);
    return 0;
}