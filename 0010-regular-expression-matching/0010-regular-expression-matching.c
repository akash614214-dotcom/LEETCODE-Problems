#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatch(char* s, char* p) {
    int x = strlen(s);
    int y = strlen(p);
    
    bool **d = (bool **)malloc((x + 1) * sizeof(bool *));
    for (int i = 0; i <= x; i++) {
        d[i] = (bool *)malloc((y + 1) * sizeof(bool));
        for (int j = 0; j <= y; j++) {
            d[i][j] = false;
        }
    }
    
    d[0][0] = true;
    
    for (int j = 1; j <= y; j++) {
        if (p[j - 1] == '*') {
            d[0][j] = d[0][j - 2];
        }
    }
    
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                d[i][j] = d[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    d[i][j] = d[i][j] || d[i - 1][j];
                }
            }
        }
    }
    
    bool r = d[x][y];
    
    for (int i = 0; i <= x; i++) {
        free(d[i]);
    }
    free(d);
    
    return r;
}