/*
 * LeetCode #73: Set Matrix Zeroes
 * Difficulty: Medium
 *
 * Human approach:
 * When a cell is zero, its whole row and column must become zero. Instead
 * of remembering every zero cell (wasting memory), we mark the first cell
 * of that row and the first cell of that column. Before we overwrite them,
 * we save whether the first row / first column themselves had a zero.
 */

#include <stdio.h>

static void setZeroes(int *matrix, int m, int n)
{
    int firstRow = 0, firstCol = 0;

    for (int j = 0; j < n; j++)
        if (matrix[0 * n + j] == 0)
        {
            firstRow = 1;
            break;
        }
    for (int i = 0; i < m; i++)
        if (matrix[i * n + 0] == 0)
        {
            firstCol = 1;
            break;
        }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i * n + j] == 0)
            {
                matrix[i * n + 0] = 0;
                matrix[0 * n + j] = 0;
            }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i * n + 0] == 0 || matrix[0 * n + j] == 0)
                matrix[i * n + j] = 0;

    if (firstRow)
        for (int j = 0; j < n; j++)
            matrix[0 * n + j] = 0;

    if (firstCol)
        for (int i = 0; i < m; i++)
            matrix[i * n + 0] = 0;
}

static void printMatrix(int *m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", m[i * cols + j]);
        printf("\n");
    }
}

int main(void)
{
    int m1[9] = {1, 1, 1, 1, 0, 1, 1, 1, 1};
    setZeroes(m1, 3, 3);
    printf("Test 1:\n");
    printMatrix(m1, 3, 3);

    int m2[12] = {0, 1, 2, 0, 3, 4, 5, 2, 1, 3, 1, 5};
    setZeroes(m2, 3, 4);
    printf("Test 2:\n");
    printMatrix(m2, 3, 4);

    return 0;
}