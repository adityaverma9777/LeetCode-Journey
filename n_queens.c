#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSafe(char** board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    
    return true;
}

void solve(char** board, int row, int n, char**** result, int* returnSize, int** returnColumnSizes) {
    if (row == n) {
        result[*returnSize] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = strdup(board[i]);
        }
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n, result, returnSize, returnColumnSizes);
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char*** result = (char***)malloc(1000 * sizeof(char**));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) board[i][j] = '.';
        board[i][n] = '\0';
    }
    
    solve(board, 0, n, result, returnSize, returnColumnSizes);
    
    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    
    return result;
}
