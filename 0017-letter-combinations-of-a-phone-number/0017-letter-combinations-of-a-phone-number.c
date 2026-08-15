#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mp[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

char **letterCombinations(char *digits, int *returnSize) {
    int n = strlen(digits);
    
    if(n == 0) {
        *returnSize = 0;
        return NULL;
    }

    int total = 1;
    int i, j, k;

    for(i = 0; i < n; i++)
        total *= strlen(mp[digits[i] - '0']);

    char **ans = malloc(total * sizeof(char *));
    
    int size = 1;
    ans[0] = malloc(1);
    ans[0][0] = '\0';

    for(i = 0; i < n; i++) {
        char *s = mp[digits[i] - '0'];
        int len = strlen(s);
        int old = size;

        size *= len;

        char **temp = malloc(size * sizeof(char *));
        int p = 0;

        for(j = 0; j < old; j++) {
            for(k = 0; k < len; k++) {
                int l = strlen(ans[j]);

                temp[p] = malloc(l + 2);
                strcpy(temp[p], ans[j]);
                temp[p][l] = s[k];
                temp[p][l + 1] = '\0';

                p++;
            }
            free(ans[j]);
        }

        free(ans);
        ans = temp;
    }

    *returnSize = size;
    return ans;
}