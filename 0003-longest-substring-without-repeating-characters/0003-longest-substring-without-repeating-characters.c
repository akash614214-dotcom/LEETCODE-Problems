int lengthOfLongestSubstring(char* s) {
    int m[128] = {0};
    int l = 0, r = 0, max = 0;
    
    while (s[r] != '\0') {
        m[(unsigned char)s[r]]++;
        
        while (m[(unsigned char)s[r]] > 1) {
            m[(unsigned char)s[l]]--;
            l++;
        }
        
        int len = r - l + 1;
        if (len > max) {
            max = len;
        }
        r++;
    }
    
    return max;
}