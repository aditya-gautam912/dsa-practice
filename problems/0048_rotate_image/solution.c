/*
 * LeetCode #48: Rotate Image
 * Difficulty: Medium
 *
 * Human approach:
 * Rotating an image 90° clockwise is the same as two easy steps:
 * 1. Transpose: think of turning the matrix along its main diagonal
 *    (swap each element with its mirror across the diagonal).
 * 2. Reverse each row. That's it!
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* LeetCode solution. Modifies the matrix in place.
   matrix is given as a 1-D flattening of the n x n square for simplicity. */
void rotate(int *matrix, int matrixSize)
{
    int n = matrixSize;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&matrix[i * n + j], &matrix[j * n + i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(&matrix[i * n + j], &matrix[i * n + n - 1 - j]);
        }
    }
}

static void printMatrix(int *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", m[i * n + j]);
        printf("\n");
    }
}

int main(void)
{
    int m1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotate(m1, 3);
    printf("Test 1:\n");
    printMatrix(m1, 3);

    int m2[4] = {1, 2, 3, 4};
    rotate(m2, 2);
    printf("Test 2:\n");
    printMatrix(m2, 2);

    return 0;
}