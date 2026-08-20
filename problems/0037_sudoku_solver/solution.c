/*
 * Sudoku Solver (LeetCode #37, Hard)
 *
 * Backtracking: for each empty cell try every digit 1-9 that does
 * not already appear in its row, column or 3x3 box. Same bitmask
 * trick as Valid Sudoku (#36) keeps the legality checks O(1).
 * When a branch leads to a dead end, undo the move and try the
 * next digit — the board is guaranteed to have exactly one solution.
 */

#include <stdbool.h>
#include <stdio.h>

static int rowMask[9], colMask[9], boxMask[9];

static int boxIndex(int r, int c)
{
    return (r / 3) * 3 + c / 3;
}

static bool solve(char **board)
{
    int r = -1, c = -1;
    for (int i = 0; i < 9 && r == -1; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.')
            {
                r = i;
                c = j;
                break;
            }

    if (r == -1)
        return true; /* no empty cell left — solved */

    int box = boxIndex(r, c);
    for (int d = 1; d <= 9; d++)
    {
        int bit = 1 << (d - 1);
        if (rowMask[r] & bit || colMask[c] & bit || boxMask[box] & bit)
            continue; /* digit already used in this row/col/box */

        board[r][c] = (char)('0' + d);
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[box] |= bit;

        if (solve(board))
            return true;

        board[r][c] = '.';
        rowMask[r] &= ~bit;
        colMask[c] &= ~bit;
        boxMask[box] &= ~bit;
    }
    return false;
}

/* LeetCode solution. Mutates the board in place until it is solved. */
void solveSudoku(char **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < 9; i++)
        rowMask[i] = colMask[i] = boxMask[i] = 0;

    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (board[r][c] != '.')
            {
                int bit = 1 << (board[r][c] - '1');
                rowMask[r] |= bit;
                colMask[c] |= bit;
                boxMask[boxIndex(r, c)] |= bit;
            }

    solve(board);
}

static void print_board(char **b)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%c ", b[i][j]);
        printf("\n");
    }
}

int main(void)
{
    char grid[9][10] = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };
    char *board[9];
    int cols[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    for (int i = 0; i < 9; i++)
        board[i] = grid[i];

    solveSudoku(board, 9, cols);
    print_board(board);
    return 0;
}