#include <stdlib.h>

void f(int *a, int n, int k, int **r, int *rs)
{
    if (k == n) {
        r[*rs] = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            r[*rs][i] = a[i];
        (*rs)++;
        return;
    }

    for (int i = k; i < n; i++) {
        int t = a[k];
        a[k] = a[i];
        a[i] = t;

        f(a, n, k + 1, r, rs);

        t = a[k];
        a[k] = a[i];
        a[i] = t;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int n = numsSize;
    int x = 1;

    for (int i = 2; i <= n; i++)
        x *= i;

    int **r = malloc(x * sizeof(int *));
    *returnColumnSizes = malloc(x * sizeof(int));
    *returnSize = 0;

    f(nums, n, 0, r, returnSize);

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = n;

    return r;
}