#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize, n = matrixColSize[0];
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int idx = 0;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            result[idx++] = matrix[top][i];
        top++;
        
        for (int i = top; i <= bottom; i++)
            result[idx++] = matrix[i][right];
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[idx++] = matrix[bottom][i];
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[idx++] = matrix[i][left];
            left++;
        }
    }
    
    return result;
}
