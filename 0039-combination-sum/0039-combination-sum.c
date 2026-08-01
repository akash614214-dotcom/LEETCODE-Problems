/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

void dfs(int *a, int n, int t, int i, int *p, int k, int ***r, int *rs, int **cs) {
    if (t == 0) {
        *r = realloc(*r, (*rs + 1) * sizeof(int *));
        (*r)[*rs] = malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
            (*r)[*rs][j] = p[j];
        *cs = realloc(*cs, (*rs + 1) * sizeof(int));
        (*cs)[*rs] = k;
        (*rs)++;
        return;
    }

    for (int j = i; j < n; j++) {
        if (a[j] > t)
            continue;
        p[k] = a[j];
        dfs(a, n, t - a[j], j, p, k + 1, r, rs, cs);
    }
}

int** combinationSum(int* a, int n, int t, int* rs, int** cs) {
    int **r = NULL;
    int *p = malloc(200 * sizeof(int));
    *rs = 0;
    *cs = NULL;

    dfs(a, n, t, 0, p, 0, &r, rs, cs);

    free(p);
    return r;
}