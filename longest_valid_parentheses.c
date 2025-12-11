#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char* s) {
    int maxLen = 0;
    int* stack = (int*)malloc(sizeof(int) * (strlen(s) + 1));
    int top = -1;
    stack[++top] = -1;
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen) maxLen = len;
            }
        }
    }
    
    free(stack);
    return maxLen;
}
