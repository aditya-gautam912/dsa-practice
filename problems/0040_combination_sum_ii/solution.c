/*
 * Combination Sum II (LeetCode #40, Medium)
 *
 * Same backtracking skeleton as #39, two key differences:
 *  - each candidate may be used AT MOST ONCE → advance to i+1
 *    when we take it.
 *  - candidates may contain duplicates; to avoid duplicate
 *    combinations we skip an element if it's the same as the
 *    previous one AND we're at the same recursion depth
 *    (i > start && c[i] == c[i-1]).
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
        if (i > start && c[i] == c[i - 1])
            continue;               /* skip duplicate at this depth */
        if (c[i] > target)
            break;                  /* sorted → prune */
        path[pathLen] = c[i];
        backtrack(c, n, target - c[i], i + 1, path, pathLen + 1,
                  res, cols, count);
    }
}

/* LeetCode solution. Returns all unique combinations where each
 * number is used at most once. */
int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), cmp_int);

    int maxCombos = 1000;
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
    int c1[] = {10, 1, 2, 7, 6, 1, 5};
    int sz1, *cols1;
    int **r1 = combinationSum2(c1, 7, 8, &sz1, &cols1);
    printf("candidates=[10,1,2,7,6,1,5], target=8\n");
    print_combos(r1, sz1, cols1);

    int c2[] = {2, 5, 2, 1, 2};
    int sz2, *cols2;
    int **r2 = combinationSum2(c2, 5, 5, &sz2, &cols2);
    printf("candidates=[2,5,2,1,2], target=5\n");
    print_combos(r2, sz2, cols2);
    return 0;
}