void nextPermutation(int* nums, int n) {
    int i, j, t;

    i = n - 2;

    while (i >= 0) {
        if (nums[i] < nums[i + 1])
            break;
        i--;
    }

    if (i < 0) {
        i = 0;
        j = n - 1;

        while (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }

        return;
    }

    j = n - 1;

    while (j > i) {
        if (nums[j] > nums[i])
            break;
        j--;
    }

    t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;

    i++;
    j = n - 1;

    while (i < j) {
        t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        i++;
        j--;
    }
}