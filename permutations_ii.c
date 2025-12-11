#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

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
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = 1;
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, used, current, currentSize + 1, result, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int** result = (int**)malloc(10000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;
    int used[numsSize];
    int current[numsSize];
    for (int i = 0; i < numsSize; i++) used[i] = 0;
    
    backtrack(nums, numsSize, used, current, 0, result, returnSize, returnColumnSizes);
    
    return result;
}
