#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int n, int target) {
    int i, l, r, s, ans, d1, d2;

    qsort(nums, n, sizeof(int), cmp);

    ans = nums[0] + nums[1] + nums[2];

    for (i = 0; i < n - 2; i++) {
        l = i + 1;
        r = n - 1;

        while (l < r) {
            s = nums[i] + nums[l] + nums[r];

            d1 = abs(s - target);
            d2 = abs(ans - target);

            if (d1 < d2)
                ans = s;

            if (s < target)
                l++;
            else if (s > target)
                r--;
            else
                return s;
        }
    }

    return ans;
}