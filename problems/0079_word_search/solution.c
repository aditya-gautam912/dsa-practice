/*
 * Word Search (LeetCode #79, Medium)
 *
 * Classic grid DFS: for each starting cell that matches the first
 * letter, walk the word through up/down/left/right neighbors. Mark
 * the current cell visited (temporarily) so we never reuse a cell
 * inside one path, then restore it when backtracking.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool dfs(char **board, int rows, int cols, int r, int c,
                char *word, int k)
{
    if (word[k] == '\0')
        return true;                /* walked the whole word */
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;               /* walked off the board */
    if (board[r][c] != word[k])
        return false;               /* letter does not match */

    char keep = board[r][c];
    board[r][c] = '\0';             /* mark visited for this path */

    bool found = dfs(board, rows, cols, r + 1, c, word, k + 1) ||
                 dfs(board, rows, cols, r - 1, c, word, k + 1) ||
                 dfs(board, rows, cols, r, c + 1, word, k + 1) ||
                 dfs(board, rows, cols, r, c - 1, word, k + 1);

    board[r][c] = keep;             /* restore for other paths */
    return found;
}

/* LeetCode solution. Returns true if the word can be built from
 * adjacent cells, each cell used at most once per path. */
bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int r = 0; r < boardSize; r++)
        for (int c = 0; c < boardColSize[r]; c++)
            if (board[r][c] == word[0] &&
                dfs(board, boardSize, boardColSize[r], r, c, word, 0))
                return true;
    return false;
}

static char **make_board(char *rows[], int rowsCount, int cols)
{
    char **b = (char **)malloc(rowsCount * sizeof(char *));
    for (int i = 0; i < rowsCount; i++)
        b[i] = (char *)malloc(cols * sizeof(char));
    return b;
}

static void fill_board(char **b, char *rows[], int rowsCount, int cols)
{
    for (int i = 0; i < rowsCount; i++)
        for (int j = 0; j < cols; j++)
            b[i][j] = rows[i][j];
}

static void free_board(char **b, int rowsCount)
{
    for (int i = 0; i < rowsCount; i++)
        free(b[i]);
    free(b);
}

int main(void)
{
    char *grid[3] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    int cols = 4;
    int boardSize = 3;
    int boardColSize[3] = {cols, cols, cols};

    char **board = make_board(grid, boardSize, cols);
    fill_board(board, grid, boardSize, cols);
    printf("word=ABCCED -> %s\n", exist(board, boardSize, boardColSize, "ABCCED") ? "true" : "false");

    fill_board(board, grid, boardSize, cols);
    printf("word=SEE   -> %s\n", exist(board, boardSize, boardColSize, "SEE") ? "true" : "false");

    fill_board(board, grid, boardSize, cols);
    printf("word=ABCB  -> %s\n", exist(board, boardSize, boardColSize, "ABCB") ? "true" : "false");

    free_board(board, boardSize);
    return 0;
}