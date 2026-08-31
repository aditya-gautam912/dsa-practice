/*
 * Spiral Matrix (LeetCode #54, Medium)
 *
 * Walk the matrix in a shrinking rectangle: right
 * across the top row, down the right column, left
 * across the bottom row, up the left column. After
 * each full loop shrink the four boundaries inward.
 * Stop when all elements have been visited.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns the elements of the matrix
 * in spiral order. *returnSize = number of elements. */
int *spiralOrder(int **matrix, int matrixSize,
                  int *matrixColSize, int *returnSize)
{
    int total = matrixSize * matrixColSize[0];
    int *res = (int *)malloc(total * sizeof(int));
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    int idx = 0;

    while (idx < total)
    {
        for (int c = left; c <= right && idx < total; c++)
            res[idx++] = matrix[top][c];
        top++;

        for (int r = top; r <= bottom && idx < total; r++)
            res[idx++] = matrix[r][right];
        right--;

        for (int c = right; c >= left && idx < total; c--)
            res[idx++] = matrix[bottom][c];
        bottom--;

        for (int r = bottom; r >= top && idx < total; r--)
            res[idx++] = matrix[r][left];
        left++;
    }

    *returnSize = total;
    return res;
}

static void print_spiral(int *res, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", res[i]);
        if (i + 1 < n)
            printf(", ");
    }
    printf("]\n");
    free(res);
}

int main(void)
{
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    int *m1[] = {row0, row1, row2};
    int cols1[3] = {3, 3, 3};
    int sz1;
    int *r1 = spiralOrder(m1, 3, cols1, &sz1);
    printf("3x3: ");
    print_spiral(r1, sz1);

    int row3[] = {1, 2, 3, 4};
    int row4[] = {5, 6, 7, 8};
    int row5[] = {9, 10, 11, 12};
    int *m2[] = {row3, row4, row5};
    int cols2[3] = {4, 4, 4};
    int sz2;
    int *r2 = spiralOrder(m2, 3, cols2, &sz2);
    printf("3x4: ");
    print_spiral(r2, sz2);

    int row6[] = {1};
    int *m3[] = {row6};
    int cols3[1] = {1};
    int sz3;
    int *r3 = spiralOrder(m3, 1, cols3, &sz3);
    printf("1x1: ");
    print_spiral(r3, sz3);
    return 0;
}