#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    if (!s || strlen(s) == 0) return "";
    
    int n = strlen(s);
    int m = 2 * n + 3;
    char* t = malloc(m);
    
    t[0] = '$';
    t[1] = '#';
    for (int i = 0; i < n; i++) {
        t[2 * i + 2] = s[i];
        t[2 * i + 3] = '#';
    }
    t[m - 1] = '\0';
    
    int* p = calloc(m, sizeof(int));
    int c = 0, r = 0;
    int ml = 0, idx = 0;
    
    for (int i = 1; i < m - 1; i++) {
        int im = 2 * c - i;
        if (r > i) {
            p[i] = (r - i < p[im]) ? r - i : p[im];
        }
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
        if (p[i] > ml) {
            ml = p[i];
            idx = i;
        }
    }
    
    int start = (idx - 1 - ml) / 2;
    s[start + ml] = '\0';
    
    free(t);
    free(p);
    
    return s + start;
}