int jump(int* nums, int n) {
    int dp[n];

    dp[0] = 0;

    for (int i = 1; i < n; i++)
        dp[i] = 1000000;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            if (dp[i] + 1 < dp[i + j])
                dp[i + j] = dp[i] + 1;
        }
    }

    return dp[n - 1];
}