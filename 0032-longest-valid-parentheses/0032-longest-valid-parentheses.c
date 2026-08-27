#include <stdio.h>
#include <string.h>

int longestValidParentheses(char *s) {
    int n = strlen(s);
    int st[n + 1];
    int top = 0;
    int ans = 0;

    st[0] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st[++top] = i;
        } else {
            top--;

            if (top < 0) {
                st[++top] = i;
            } else {
                int len = i - st[top];
                if (len > ans)
                    ans = len;
            }
        }
    }

    return ans;
}
