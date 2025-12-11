#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

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
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, 
                  current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, 
                      int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    int current[100];
    
    backtrack(candidates, candidatesSize, target, 0, current, 0, result, returnSize, returnColumnSizes);
    
    return result;
}
