/*
 * Rotate Image (LeetCode #48, Medium)
 *
 * 90-degree clockwise rotation = transpose + reverse each row.
 * Once you see that, the code writes itself. I remember fumbling
 * with four-way swaps on my first try; doing it in two passes is
 * way less error-prone.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void rotate(int *matrix, int matrixSize)
{
    int n = matrixSize;

    /* transpose: mirror over the main diagonal */
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(&matrix[i * n + j], &matrix[j * n + i]);

    /* reverse each row */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            swap(&matrix[i * n + j], &matrix[i * n + n - 1 - j]);
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
    rotate(3, m1);
    printMatrix(m1, 3);

    int m2[4] = {1, 2, 3, 4};
    rotate(2, m2);
    printMatrix(m2, 2);

    return 0;
}