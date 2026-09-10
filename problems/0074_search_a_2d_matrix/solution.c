/*
 * Search a 2D Matrix (LeetCode #74, Medium)
 *
 * The matrix is effectively a flattened sorted array because:
 * - each row is sorted left to right
 * - first element of each row > last element of previous row
 * So we can binary search the virtual 1D array of size m*n,
 * mapping index -> (row = idx / n, col = idx % n).
 */

#include <stdbool.h>
#include <stdio.h>

/* LeetCode solution. Returns true if target is found. */
bool searchMatrix(int **matrix, int matrixSize,
                  int *matrixColSize, int target)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    int left = 0, right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int r = mid / n;
        int c = mid % n;
        int val = matrix[r][c];

        if (val == target)
            return true;
        else if (val < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main(void)
{
    int r0[] = {1, 3, 5, 7};
    int r1[] = {10, 11, 16, 20};
    int r2[] = {23, 30, 34, 60};
    int *m1[] = {r0, r1, r2};
    int c1[3] = {4, 4, 4};

    printf("target=3   -> %s (expected true)\n",
           searchMatrix(m1, 3, c1, 3) ? "true" : "false");
    printf("target=13  -> %s (expected false)\n",
           searchMatrix(m1, 3, c1, 13) ? "true" : "false");

    int single[] = {1};
    int *m2[] = {single};
    int c2[1] = {1};
    printf("target=1   -> %s (expected true)\n",
           searchMatrix(m2, 1, c2, 1) ? "true" : "false");
    return 0;
}