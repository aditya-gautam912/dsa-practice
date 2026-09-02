/*
 * Insert Interval (LeetCode #57, Medium)
 *
 * Given a sorted list of non-overlapping intervals and a
 * new interval, insert the new interval and merge any
 * overlapping ones in one pass. Three phases:
 *  1) add all intervals ending before newInterval starts,
 *  2) merge all overlapping intervals with newInterval,
 *  3) add the remaining intervals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LeetCode solution. Returns the merged list of intervals. */
int **insert(int **intervals, int intervalsSize,
               int *intervalsColSize, int *newInterval,
               int newIntervalSize, int *returnSize,
               int **returnColumnSizes)
{
    int **res = (int **)malloc((intervalsSize + 1) * sizeof(int *));
    int *cols = (int *)malloc((intervalsSize + 1) * sizeof(int));
    int count = 0;
    int i = 0;

    /* phase 1: all intervals ending before newInterval starts */
    while (i < intervalsSize && intervals[i][1] < newInterval[0])
    {
        res[count] = (int *)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        cols[count] = 2;
        count++;
        i++;
    }

    /* phase 2: merge overlapping intervals */
    int merged[2] = {newInterval[0], newInterval[1]};
    while (i < intervalsSize && intervals[i][0] <= merged[1])
    {
        if (intervals[i][0] < merged[0])
            merged[0] = intervals[i][0];
        if (intervals[i][1] > merged[1])
            merged[1] = intervals[i][1];
        i++;
    }
    res[count] = (int *)malloc(2 * sizeof(int));
    res[count][0] = merged[0];
    res[count][1] = merged[1];
    cols[count] = 2;
    count++;

    /* phase 3: remaining intervals */
    while (i < intervalsSize)
    {
        res[count] = (int *)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        cols[count] = 2;
        count++;
        i++;
    }

    *returnSize = count;
    *returnColumnSizes = cols;
    return res;
}

static void print_intervals(int **res, int count, int *cols)
{
    printf("[");
    for (int i = 0; i < count; i++)
    {
        printf("[%d,%d]", res[i][0], res[i][1]);
        if (i + 1 < count)
            printf(",");
        free(res[i]);
    }
    printf("]\n");
    free(res);
    free(cols);
}

int main(void)
{
    /* test 1: intervals=[[1,3],[6,9]], new=[2,5] */
    int r0[] = {1, 3}, r1[] = {6, 9};
    int *m1[] = {r0, r1};
    int c1[2] = {2, 2};
    int new1[] = {2, 5};
    int sz1;
    int *colSz1;
    int **r1_out = insert(m1, 2, c1, new1, 2, &sz1, &colSz1);
    printf("intervals=[[1,3],[6,9]], new=[2,5] -> ");
    print_intervals(r1_out, sz1, colSz1);

    /* test 2: intervals=[[1,2],[3,5],[6,7],[8,10],[12,16]], new=[4,8] */
    int a1[] = {1, 2}, a2[] = {3, 5}, a3[] = {6, 7}, a4[] = {8, 10}, a5[] = {12, 16};
    int *m2[] = {a1, a2, a3, a4, a5};
    int c2[5] = {2, 2, 2, 2, 2};
    int new2[] = {4, 8};
    int sz2;
    int *colSz2;
    int **r2_out = insert(m2, 5, c2, new2, 2, &sz2, &colSz2);
    printf("intervals=[[1,2],[3,5],[6,7],[8,10],[12,16]], new=[4,8] -> ");
    print_intervals(r2_out, sz2, colSz2);
    return 0;
}