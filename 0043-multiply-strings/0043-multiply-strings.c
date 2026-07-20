char* multiply(char* a, char* b) {
    int n1 = strlen(a);
    int n2 = strlen(b);

    if (n1 == 0 || n2 == 0) return "0";
    if (a[0] == '0' || b[0] == '0') return "0";

    int* r = (int*)calloc(n1 + n2, sizeof(int));

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int p = (a[i] - '0') * (b[j] - '0');
            int sum = p + r[i + j + 1];

            r[i + j + 1] = sum % 10;
            r[i + j] += sum / 10;
        }
    }

    int i = 0;
    while (i < n1 + n2 && r[i] == 0) {
        i++;
    }

    if (i == n1 + n2) {
        free(r);
        char* res = (char*)malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    char* res = (char*)malloc(n1 + n2 - i + 1);
    int k = 0;
    while (i < n1 + n2) {
        res[k++] = r[i++] + '0';
    }
    res[k] = '\0';

    free(r);
    return res;
}