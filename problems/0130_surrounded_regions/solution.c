/*
 * Surrounded Regions (LeetCode #130, Medium)
 *
 * Mark every region connected to the border as safe. Any remaining 'O'
 * is surrounded and can be flipped to 'X'.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
} Cell;

static void markSafe(char **board, int rows, int cols, int startRow, int startCol)
{
    if (board[startRow][startCol] != 'O')
        return;

    Cell *stack = (Cell *)malloc((size_t)rows * (size_t)cols * sizeof(Cell));
    int top = 0;
    stack[top++] = (Cell){startRow, startCol};
    board[startRow][startCol] = 'T';

    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    while (top > 0)
    {
        Cell current = stack[--top];
        for (int direction = 0; direction < 4; direction++)
        {
            int nextRow = current.row + dr[direction];
            int nextCol = current.col + dc[direction];
            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
                continue;
            if (board[nextRow][nextCol] != 'O')
                continue;

            board[nextRow][nextCol] = 'T';
            stack[top++] = (Cell){nextRow, nextCol};
        }
    }

    free(stack);
}

/* LeetCode solution. Modifies board in place. */
void solve(char **board, int boardSize, int *boardColSize)
{
    if (boardSize == 0 || boardColSize == NULL || *boardColSize == 0)
        return;

    int rows = boardSize;
    int cols = *boardColSize;

    for (int row = 0; row < rows; row++)
    {
        markSafe(board, rows, cols, row, 0);
        markSafe(board, rows, cols, row, cols - 1);
    }
    for (int col = 0; col < cols; col++)
    {
        markSafe(board, rows, cols, 0, col);
        markSafe(board, rows, cols, rows - 1, col);
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == 'O')
                board[row][col] = 'X';
            else if (board[row][col] == 'T')
                board[row][col] = 'O';
        }
    }
}

int main(void)
{
    char row0[] = {'X', 'X', 'X', 'X'};
    char row1[] = {'X', 'O', 'O', 'X'};
    char row2[] = {'X', 'X', 'O', 'X'};
    char row3[] = {'X', 'O', 'X', 'X'};
    char *board[] = {row0, row1, row2, row3};
    int cols = 4;

    solve(board, 4, &cols);
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < cols; col++)
            printf("%c ", board[row][col]);
        putchar('\n');
    }
    return 0;
}
