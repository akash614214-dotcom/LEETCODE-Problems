/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int a[101];

int* plusOne(int* d, int n, int* r) {
    for (int i = 0; i < n; i++)
        a[i] = d[i];

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 9) {
            a[i]++;
            *r = n;
            return a;
        }
        a[i] = 0;
    }

    for (int i = n; i > 0; i--)
        a[i] = 0;

    a[0] = 1;
    *r = n + 1;
    return a;
}