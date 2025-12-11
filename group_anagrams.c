#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** groups = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    *returnSize = 0;
    
    char** sorted = (char**)malloc(strsSize * sizeof(char*));
    for (int i = 0; i < strsSize; i++) {
        sorted[i] = strdup(strs[i]);
        int len = strlen(sorted[i]);
        for (int j = 0; j < len - 1; j++) {
            for (int k = j + 1; k < len; k++) {
                if (sorted[i][j] > sorted[i][k]) {
                    char temp = sorted[i][j];
                    sorted[i][j] = sorted[i][k];
                    sorted[i][k] = temp;
                }
            }
        }
    }
    
    int* used = (int*)calloc(strsSize, sizeof(int));
    for (int i = 0; i < strsSize; i++) {
        if (used[i]) continue;
        groups[*returnSize] = (char**)malloc(strsSize * sizeof(char*));
        int count = 0;
        groups[*returnSize][count++] = strs[i];
        used[i] = 1;
        
        for (int j = i + 1; j < strsSize; j++) {
            if (!used[j] && strcmp(sorted[i], sorted[j]) == 0) {
                groups[*returnSize][count++] = strs[j];
                used[j] = 1;
            }
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }
    
    for (int i = 0; i < strsSize; i++) free(sorted[i]);
    free(sorted);
    free(used);
    
    return groups;
}
