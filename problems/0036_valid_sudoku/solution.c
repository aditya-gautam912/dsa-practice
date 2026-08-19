/*
 * Valid Sudoku (LeetCode #36, Medium)
 *
 * A board is valid if every row, every column and every 3x3 box
 * has no repeated digits. Keep a 9-bit mask per row, per column
 * and per box — each digit owns one bit, so a duplicate shows up
 * as an already-set bit. One pass over the whole board, O(1) space.
 */

#include <stdbool.h>
#include <stdio.h>

/* LeetCode solution. board is a 9x9 grid, '.' marks an empty cell. */
bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int rowMask[9] = {0}, colMask[9] = {0}, boxMask[9] = {0};

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char cell = board[r][c];
            if (cell == '.')
                continue;

            int bit = 1 << (cell - '1');
            int box = (r / 3) * 3 + c / 3;

            if (rowMask[r] & bit)
                return false; /* digit already in this row */
            if (colMask[c] & bit)
                return false; /* digit already in this column */
            if (boxMask[box] & bit)
                return false; /* digit already in this 3x3 box */

            rowMask[r] |= bit;
            colMask[c] |= bit;
            boxMask[box] |= bit;
        }
    }
    return true;
}

static char *rows[9];
static char grid[9][10];

static void setup(char *b[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            grid[i][j] = b[i][j];
        grid[i][9] = '\0';
        rows[i] = grid[i];
    }
}

int main(void)
{
    char valid[9][10] = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };
    char badRow[9][10] = {
        "55..7....", "6..195...", ".98....6.", /* two 5s in row 0 */
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };
    char badBox[9][10] = {
        "63..7....", "6..195...", ".98....6.", /* two 6s in top-left box */
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };
    char *b[9];
    for (int i = 0; i < 9; i++)
        b[i] = valid[i];

    int cols[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    setup(b);
    printf("valid board -> %s\n", isValidSudoku(rows, 9, cols) ? "true" : "false");

    for (int i = 0; i < 9; i++)
        b[i] = badRow[i];
    setup(b);
    printf("duplicate in row -> %s\n", isValidSudoku(rows, 9, cols) ? "true" : "false");

    for (int i = 0; i < 9; i++)
        b[i] = badBox[i];
    setup(b);
    printf("duplicate in 3x3 box -> %s\n", isValidSudoku(rows, 9, cols) ? "true" : "false");
    return 0;
}