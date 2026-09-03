/*
 * Spiral Matrix II (LeetCode #59, Medium)
 *
 * Same shrinking-rectangle idea as #54 (Spiral Matrix),
 * but this time we WRITE numbers 1..n² into the matrix.
 * Walk right across top, down the right, left across
 * the bottom, up the left — shrinking boundaries after
 * each loop until all n² cells are filled.
 */

#include <stdio.h>
#include <stdlib.h>

/* LeetCode solution. Returns an n x n matrix filled
 * with numbers 1 to n² in spiral order. */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(n * sizeof(int *));
    for (int r = 0; r < n; r++)
    {
        res[r] = (int *)malloc(n * sizeof(int));
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int val = 1;
    int total = n * n;

    while (val <= total)
    {
        for (int c = left; c <= right && val <= total; c++)
            res[top][c] = val++;
        top++;

        for (int r = top; r <= bottom && val <= total; r++)
            res[r][right] = val++;
        right--;

        for (int c = right; c >= left && val <= total; c--)
            res[bottom][c] = val++;
        bottom--;

        for (int r = bottom; r >= top && val <= total; r--)
            res[r][left] = val++;
        left++;
    }

    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        (*returnColumnSizes)[i] = n;
    return res;
}

static void print_matrix(int **m, int n)
{
    printf("[");
    for (int r = 0; r < n; r++)
    {
        printf("[");
        for (int c = 0; c < n; c++)
        {
            printf("%d", m[r][c]);
            if (c + 1 < n)
                printf(",");
        }
        printf("]");
        if (r + 1 < n)
            printf(",");
        free(m[r]);
    }
    printf("]\n");
    free(m);
}

int main(void)
{
    int sz3, *cols3;
    int **m3 = generateMatrix(3, &sz3, &cols3);
    printf("n=3 -> ");
    print_matrix(m3, sz3);

    int sz1, *cols1;
    int **m1 = generateMatrix(1, &sz1, &cols1);
    printf("n=1 -> ");
    print_matrix(m1, sz1);
    return 0;
}