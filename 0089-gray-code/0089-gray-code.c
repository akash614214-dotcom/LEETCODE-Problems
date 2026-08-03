int* grayCode(int n, int* rs) {
    int s = 1 << n;
    int *a = (int *)malloc(s * sizeof(int));
    int i;

    *rs = s;

    for (i = 0; i < s; i++)
        a[i] = i ^ (i >> 1);

    return a;
}