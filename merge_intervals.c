#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    *returnSize = 1;
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[*returnSize - 1][1]) {
            if (intervals[i][1] > result[*returnSize - 1][1])
                result[*returnSize - 1][1] = intervals[i][1];
        } else {
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    
    return result;
}
