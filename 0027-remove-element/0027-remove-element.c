int removeElement(int* a, int n, int v) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        if (a[i] != v) {
            a[j] = a[i];
            j++;
        }
    }
    return j;
}