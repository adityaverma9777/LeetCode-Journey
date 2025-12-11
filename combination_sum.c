#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start, 
               int* current, int currentSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        result[*returnSize] = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) continue;
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, 
                  current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    int current[100];
    
    backtrack(candidates, candidatesSize, target, 0, current, 0, result, returnSize, returnColumnSizes);
    
    return result;
}
