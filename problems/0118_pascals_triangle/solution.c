/*
 * Pascal's Triangle (LeetCode #118, Easy)
 *
 * Each row is built from the previous one: first and last
 * elements are 1, interior elements are sum of the two
 * numbers above. Can build iteratively with O(1) extra space
 * by updating the row in reverse.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LeetCode solution. Returns first numRows rows of Pascal's triangle. */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(numRows * sizeof(int *));
    int *cols = (int *)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++)
    {
        res[i] = (int *)malloc((i + 1) * sizeof(int));
        cols[i] = i + 1;
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++)
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }

    *returnSize = numRows;
    *returnColumnSizes = cols;
    return res;
}

static void print_triangle(int **t, int rows, int *cols)
{
    for (int i = 0; i < rows; i++)
    {
        printf("[");
        for (int j = 0; j < cols[i]; j++)
        {
            printf("%d", t[i][j]);
            if (j + 1 < cols[i])
                printf(",");
        }
        printf("]\n");
        free(t[i]);
    }
    free(t);
    free(cols);
}

int main(void)
{
    int sz, *cols;
    int **t = generate(5, &sz, &cols);
    printf("numRows=5:\n");
    print_triangle(t, sz, cols);

    int **t2 = generate(1, &sz, &cols);
    printf("numRows=1:\n");
    print_triangle(t2, sz, cols);
    return 0;
}