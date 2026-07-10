int romanToInt(char* s) {
    int map[128];
    map['I'] = 1;   map['V'] = 5;   map['X'] = 10;
    map['L'] = 50;  map['C'] = 100; map['D'] = 500; map['M'] = 1000;
    
    int sum = 0;
    int pre = 0;
    int len = 0;
    
    while(s[len] != '\0') {
        len++;
    }
    
    int mix = len * 2; 
    
    for (int i = len - 1; i >= 0; i--) {
        int cur = map[s[i]];
        if (cur >= pre) {
            sum += cur;
        } else {
            sum -= cur;
        }
        pre = cur;
    }
    
    int fin = sum;
    return fin;
}