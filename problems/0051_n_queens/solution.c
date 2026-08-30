/*
 * N-Queens (LeetCode #51, Hard)
 *
 * Classic backtracking: place one queen per row, trying
 * every column. Three boolean arrays track which columns
 * and which diagonals are already occupied, giving O(1)
 * attack checks. When row == n we have a valid placement.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void place_queens(int n, int row, int *cols,
                           int *diag1, int *diag2,
                           int *place, char ***res, int *count)
{
    if (row == n)
    {
        char **board = (char **)malloc(n * sizeof(char *));
        for (int r = 0; r < n; r++)
        {
            board[r] = (char *)malloc((n + 1) * sizeof(char));
            for (int c = 0; c < n; c++)
                board[r][c] = (place[r] == c) ? 'Q' : '.';
            board[r][n] = '\0';
        }
        res[*count] = board;
        (*count)++;
        return;
    }

    for (int c = 0; c < n; c++)
    {
        int d1 = row - c + (n - 1);
        int d2 = row + c;
        if (cols[c] || diag1[d1] || diag2[d2])
            continue;
        cols[c] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;
        place[row] = c;
        place_queens(n, row + 1, cols, diag1, diag2, place, res, count);
        cols[c] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

/* LeetCode solution. Returns all distinct n-queens placements. */
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    char ***res = (char ***)malloc(500 * sizeof(char **));
    int count = 0;
    int cols[9] = {0};
    int diag1[17] = {0};
    int diag2[17] = {0};
    int place[9];

    place_queens(n, 0, cols, diag1, diag2, place, res, &count);

    *returnSize = count;
    *returnColumnSizes = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        (*returnColumnSizes)[i] = n;
    return res;
}

static void print_board(char **b, int n)
{
    for (int r = 0; r < n; r++)
        printf("%s\n", b[r]);
    printf("\n");
}

int main(void)
{
    for (int n = 1; n <= 4; n++)
    {
        int cols[9] = {0}, diag1[17] = {0}, diag2[17] = {0};
        int place[9];
        int count = 0;
        char ***res = (char ***)malloc(500 * sizeof(char **));
        place_queens(n, 0, cols, diag1, diag2, place, res, &count);

        printf("n=%d -> %d solution(s)\n", n, count);
        if (n == 4)
        {
            for (int i = 0; i < count; i++)
            {
                print_board(res[i], n);
                free(res[i]);
            }
        }
        free(res);
    }
    return 0;
}