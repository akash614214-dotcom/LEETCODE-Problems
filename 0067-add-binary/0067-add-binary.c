char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int c = 0, k = 0;
    int n = (i > j ? i : j) + 3;

    char *r = (char *)malloc(n);

    while (i >= 0 || j >= 0 || c) {
        int s = c;

        if (i >= 0)
            s += a[i--] - '0';

        if (j >= 0)
            s += b[j--] - '0';

        r[k++] = (s % 2) + '0';
        c = s / 2;
    }

    r[k] = '\0';

    for (int l = 0, h = k - 1; l < h; l++, h--) {
        char t = r[l];
        r[l] = r[h];
        r[h] = t;
    }

    return r;
}