int strStr(char* h, char* n) {
    int hl = 0;
    int nl = 0;

    while (h[hl] != '\0') {
        hl++;
    }
    while (n[nl] != '\0') {
        nl++;
    }

    if (nl == 0) {
        return 0;
    }
    if (hl < nl) {
        return -1;
    }

    for (int i = 0; i <= hl - nl; i++) {
        int j = 0;
        while (j < nl && h[i + j] == n[j]) {
            j++;
        }
        if (j == nl) {
            return i;
        }
    }

    return -1;
}