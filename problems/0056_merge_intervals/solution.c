/*
 * Merge Intervals (LeetCode #56, Medium)
 *
 * Sort by start, then just walk once. Either the next interval
 * starts after the current one ends (new entry), or it overlaps
 * and we stretch the end. The sorting is doing the hard work;
 * after that it's almost trivial.
 *
 * Note: this one I keep pointing out in interviews - the merge
 * condition is "start <= current end", not "they share a point".
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    return ia[0] - ib[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes)
{
    int **merged = (int **)malloc(intervalsSize * sizeof(int *));
    int *cols = (int *)malloc(intervalsSize * sizeof(int));
    int n = 0;

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    for (int i = 0; i < intervalsSize; i++)
    {
        if (n == 0 || intervals[i][0] > merged[n - 1][1])
        {
            merged[n] = intervals[i];
            cols[n] = 2;
            n++;
        }
        else if (intervals[i][1] > merged[n - 1][1])
            merged[n - 1][1] = intervals[i][1];
    }

    *returnSize = n;
    *returnColumnSizes = cols;
    return merged;
}

int main(void)
{
    int ia[2] = {1, 3}, ib[2] = {2, 6}, ic[2] = {8, 10}, id[2] = {15, 18};
    int *inp[4] = {ia, ib, ic, id};
    int cols4[4] = {2, 2, 2, 2};

    int retSize, *retCols;
    int **res = merge(inp, 4, cols4, &retSize, &retCols);
    for (int i = 0; i < retSize; i++)
        printf("[%d, %d]\n", res[i][0], res[i][1]);

    free(res);
    free(retCols);
    return 0;
}