/*
 * Set Matrix Zeroes (LeetCode #73, Medium)
 *
 * The trick the problem pushes you toward: don't scan the whole
 * matrix for zeroes after the fact - instead use the first row and
 * first column as "remember here" flags. But they're part of the
 * matrix, so save whether they had a zero before you flag them.
 *
 * I honestly usually write the two-array version first, then the
 * interviewer asks "can you do it in O(1) space" and I swap in
 * this. Good party trick for interviews.
 */

#include <stdio.h>

void setZeroes(int *matrix, int m, int n)
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

    /* use first row/col as the zero-flag storage */
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

static void printM(int *m, int rows, int cols)
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
    printM(m1, 3, 3);

    int m2[12] = {0, 1, 2, 0, 3, 4, 5, 2, 1, 3, 1, 5};
    setZeroes(m2, 3, 4);
    printM(m2, 3, 4);

    return 0;
}