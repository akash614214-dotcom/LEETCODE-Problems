char* intToRoman(int num) {
    int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    char* res = (char*)malloc(sizeof(char) * 20);
    res[0] = '\0';
    
    for (int i = 0; i < 13; i++) {
        while (num >= v[i]) {
            strcat(res, s[i]);
            num -= v[i];
        }
    }
    
    return res;
}