#include <string.h>

char* longestCommonPrefix(char** strs, int strSize) {
    if (strSize == 0 || strs == NULL) {
        return "";
    }
    
    char* s = strs[0];
    int i, j;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 1; j < strSize; j++) {
            if (strs[j][i] != s[i]) {
                s[i] = '\0';
                return s;
            }
        }
    }

    
    return s;
}