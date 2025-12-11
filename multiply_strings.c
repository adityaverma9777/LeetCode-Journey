#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1), len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) return "0";
    
    int* result = (int*)calloc(len1 + len2, sizeof(int));
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    char* str = (char*)malloc(len1 + len2 + 1);
    int idx = 0, i = 0;
    
    while (i < len1 + len2 && result[i] == 0) i++;
    if (i == len1 + len2) return "0";
    
    while (i < len1 + len2) {
        str[idx++] = result[i++] + '0';
    }
    str[idx] = '\0';
    
    free(result);
    return str;
}
