#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int n = strlen(s);
    if (n % 2 != 0) return false;
    
    char st[n];
    int t = -1;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st[++t] = c;
        } else {
            if (t == -1) return false;
            if (c == ')' && st[t] != '(') return false;
            if (c == '}' && st[t] != '{') return false;
            if (c == ']' && st[t] != '[') return false;
            t--;
        }
    }
    return t == -1;
}