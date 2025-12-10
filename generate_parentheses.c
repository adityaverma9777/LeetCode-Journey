void backtrack(char** result, int* returnSize, char* current, int open, int close, int n) {
    if (strlen(current) == 2 * n) {
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    int len = strlen(current);
    if (open < n) {
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, n);
        current[len] = '\0';
    }   
    if (close < open) {
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, n);
        current[len] = '\0';
    }
}
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int maxSize = 1;
    for (int i = 0; i < n; i++) {
        maxSize *= 4;
    }
    char** result = (char**)malloc(maxSize * sizeof(char*));
    char current[2 * n + 1];
    current[0] = '\0';
    backtrack(result, returnSize, current, 0, 0, n);
    return result;
}
