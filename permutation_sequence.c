#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k) {
    int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int* nums = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) nums[i] = i + 1;
    
    k--;
    for (int i = 0; i < n; i++) {
        int idx = k / factorial[n - 1 - i];
        result[i] = nums[idx] + '0';
        
        for (int j = idx; j < n - 1; j++) {
            nums[j] = nums[j + 1];
        }
        
        k %= factorial[n - 1 - i];
    }
    result[n] = '\0';
    
    free(nums);
    return result;
}
