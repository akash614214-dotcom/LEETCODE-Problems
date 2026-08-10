#include <limits.h>

int myAtoi(char * s) {
    double r = 0;
    int g = 1;
    
    while (*s == ' ') s++;
    
    if (*s == '-' || *s == '+') {
        g = (*s == '-') ? -1 : 1;
        s++;
    }
    
    while (*s >= '0' && *s <= '9') {
        r = r * 10 + (*s - '0');
        s++;
    }
    
    r *= g;
    
    if (r >= INT_MAX) return INT_MAX;
    if (r <= INT_MIN) return INT_MIN;
    
    return (int)r;
}