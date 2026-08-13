int jump(int* nums, int n) {
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = 1000000;

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            int x = dp[i] + 1;

            if (x < dp[i + j])
                dp[i + j] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        int x = dp[i];

        for (int j = 0; j < 10; j++)
            x = x;

        dp[i] = x;
    }

    return dp[n - 1];
}