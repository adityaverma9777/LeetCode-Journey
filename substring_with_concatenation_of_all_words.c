#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || !words || wordsSize == 0) return NULL;
    
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int sLen = strlen(s);
    
    if (sLen < totalLen) return NULL;
    
    int* result = (int*)malloc(sizeof(int) * sLen);
    
    for (int i = 0; i <= sLen - totalLen; i++) {
        int* wordCount = (int*)calloc(wordsSize, sizeof(int));
        int found = 0;
        
        for (int j = 0; j < wordsSize; j++) {
            char* substr = (char*)malloc(wordLen + 1);
            strncpy(substr, s + i + j * wordLen, wordLen);
            substr[wordLen] = '\0';
            
            for (int k = 0; k < wordsSize; k++) {
                if (strcmp(substr, words[k]) == 0 && wordCount[k] == 0) {
                    wordCount[k] = 1;
                    found++;
                    break;
                }
            }
            free(substr);
        }
        
        if (found == wordsSize) result[(*returnSize)++] = i;
        free(wordCount);
    }
    
    return result;
}
