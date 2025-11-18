#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSafe(int** board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    
    return true;
}

bool solveNQueenUtil(int** board, int col, int n) {
    if (col >= n)
        return true;
    
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            
            if (solveNQueenUtil(board, col + 1, n))
                return true;
            
            board[i][col] = 0;
        }
    }
    
    return false;
}

void printSolution(int** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

bool solveNQueen(int n) {
    int** board = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = (int*)calloc(n, sizeof(int));
    }
    
    if (!solveNQueenUtil(board, 0, n)) {
        printf("Solution does not exist\n");
        for (int i = 0; i < n; i++)
            free(board[i]);
        free(board);
        return false;
    }
    
    printSolution(board, n);
    
    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
    return true;
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    
    solveNQueen(n);
    
    return 0;
}