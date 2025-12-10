char* mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char* digits, int index, char* current, int currentLen, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = (char*)malloc((currentLen + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    
    char* letters = mapping[digits[index] - '0'];
    
    for (int i = 0; letters[i] != '\0'; i++) {
        current[currentLen] = letters[i];
        current[currentLen + 1] = '\0';
        backtrack(digits, index + 1, current, currentLen + 1, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    
    if (digits == NULL || digits[0] == '\0') {
        return NULL;
    }
    
    int maxSize = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        maxSize *= 4;
    }
    
    char** result = (char**)malloc(maxSize * sizeof(char*));
    char current[100];
    current[0] = '\0';
    
    backtrack(digits, 0, current, 0, result, returnSize);
    
    return result;
}
