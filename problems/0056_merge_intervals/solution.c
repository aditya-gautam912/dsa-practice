/*
 * LeetCode #56: Merge Intervals
 * Difficulty: Medium
 *
 * Human approach:
 * First, put the intervals in order by their start time. Then look at each
 * interval; if it starts after the previous one ends, it is a new group.
 * Otherwise it overlaps, so we stretch the previous interval's end to
 * cover both. Each group is one merged interval.
 */

#include <stdio.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    return ia[0] - ib[0];
}

/* LeetCode solution.
   Returns merged intervals and sizes. Caller frees. */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes)
{
    int **merged = (int **)malloc(intervalsSize * sizeof(int *));
    int *cols = (int *)malloc(intervalsSize * sizeof(int));
    int count = 0;

    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    for (int i = 0; i < intervalsSize; i++)
    {
        if (count == 0 || intervals[i][0] > merged[count - 1][1])
        {
            merged[count] = intervals[i];
            cols[count] = 2;
            count++;
        }
        else
        {
            if (intervals[i][1] > merged[count - 1][1])
                merged[count - 1][1] = intervals[i][1];
        }
    }

    *returnSize = count;
    *returnColumnSizes = cols;
    return merged;
}

int main(void)
{
    int *intervals[4];
    int ia[2] = {1, 3}, ib[2] = {2, 6}, ic[2] = {8, 10}, id[2] = {15, 18};
    intervals[0] = ia;
    intervals[1] = ib;
    intervals[2] = ic;
    intervals[3] = id;
    int cols4[4] = {2, 2, 2, 2};

    int retSize, *retCols;
    int **res = merge(intervals, 4, cols4, &retSize, &retCols);
    for (int i = 0; i < retSize; i++)
        printf("[%d, %d]\n", res[i][0], res[i][1]);

    free(res);
    free(retCols);
    return 0;
}