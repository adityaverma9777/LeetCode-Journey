#include <stdio.h>
#include <stdbool.h>

bool isSafe(int* board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
            return false;
    }
    return true;
}

int solve(int* board, int row, int n) {
    if (row == n) return 1;
    
    int count = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;
            count += solve(board, row + 1, n);
        }
    }
    return count;
}

int totalNQueens(int n) {
    int board[n];
    return solve(board, 0, n);
}
