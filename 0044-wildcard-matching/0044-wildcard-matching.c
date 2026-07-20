#include <stdbool.h>

bool isMatch(char *s, char *p) {
    char *s_ptr = s, *p_ptr = p;
    char *s_star = NULL, *p_star = NULL;

    while (*s_ptr) {
        if (*p_ptr == '?' || *p_ptr == *s_ptr) {
            s_ptr++;
            p_ptr++;
        } else if (*p_ptr == '*') {
            p_star = p_ptr;
            s_star = s_ptr;
            p_ptr++;
        } else if (p_star) {
            p_ptr = p_star + 1;
            s_star++;
            s_ptr = s_star;
        } else {
            return false;
        }
    }

    while (*p_ptr == '*') {
        p_ptr++;
    }

    return *p_ptr == '\0';
}