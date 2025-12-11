#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int* used, int* current, int currentSize,
               int** result, int* returnSize, int** returnColumnSizes) {
    if (currentSize == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        used[i] = 1;
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, used, current, currentSize + 1, result, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    int used[numsSize];
    int current[numsSize];
    for (int i = 0; i < numsSize; i++) used[i] = 0;
    
    backtrack(nums, numsSize, used, current, 0, result, returnSize, returnColumnSizes);
    
    return result;
}
