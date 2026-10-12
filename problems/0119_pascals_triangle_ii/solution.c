/*
 * Pascal's Triangle II (LeetCode #119, Easy)
 *
 * Return the rowIndex-th row of Pascal's triangle (0-indexed).
 * Build iteratively in-place by updating from right to left
 * to avoid overwriting values needed for the next calculation.
 * O(k) extra space.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns the rowIndex-th row. */
int *getRow(int rowIndex, int *returnSize)
{
    int *row = (int *)malloc((rowIndex + 1) * sizeof(int));
    for (int i = 0; i <= rowIndex; i++)
        row[i] = 0;
    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++)
    {
        for (int j = i; j >= 1; j--)
            row[j] += row[j - 1];
    }
    *returnSize = rowIndex + 1;
    return row;
}

static void print_arr(int *a, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i + 1 < n)
            printf(",");
    }
    printf("]\n");
    free(a);
}

int main(void)
{
    int sz1;
    int *r1 = getRow(3, &sz1);
    printf("rowIndex=3 -> ");
    print_arr(r1, sz1);

    int sz2;
    int *r2 = getRow(0, &sz2);
    printf("rowIndex=0 -> ");
    print_arr(r2, sz2);

    int sz3;
    int *r3 = getRow(1, &sz3);
    printf("rowIndex=1 -> ");
    print_arr(r3, sz3);
    return 0;
}