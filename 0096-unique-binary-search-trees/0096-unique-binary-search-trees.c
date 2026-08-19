#include <stdio.h>

long long dp[20];

long long solve(int n) {
    int i;
    long long ans = 0;

    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    for (i = 1; i <= n; i++)
        ans += solve(i - 1) * solve(n - i);

    dp[n] = ans;

    return ans;
}

int numTrees(int n) {
    int i;

    for (i = 0; i <= n; i++)
        dp[i] = -1;

    return solve(n);
}

