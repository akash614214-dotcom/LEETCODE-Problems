char* convert(char* s, int r) {
    int n = strlen(s);
    if (r == 1 || r >= n) {
        char *a = (char *)malloc((n + 1) * sizeof(char));
        strcpy(a, s);
        return a;
    }

    char *a = (char *)malloc((n + 1) * sizeof(char));
    int k = 0;
    int c = 2 * r - 2;

    for (int i = 0; i < r; i++) {
        for (int j = i; j < n; j += c) {
            a[k++] = s[j];
            int x = j + c - 2 * i;
            if (i != 0 && i != r - 1 && x < n)
                a[k++] = s[x];
        }
    }

    a[k] = '\0';
    return a;
}