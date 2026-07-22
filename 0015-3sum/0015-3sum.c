/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    int cap = 1000;
    int** res = (int**)malloc(cap * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cap * sizeof(int));
    *returnSize = 0;

    if (n < 3) return res;

    qsort(nums, n, sizeof(int), cmp);

    for (int i = 0; i < n - 2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];

            if (s == 0) {
                if (*returnSize >= cap) {
                    cap *= 2;
                    res = (int**)realloc(res, cap * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, cap * sizeof(int));
                }

                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;

                l++;
                r--;
            } else if (s < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    return res;
}