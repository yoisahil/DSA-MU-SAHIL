class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 3; k++) {
                int prev = i - k;
                if (prev < 0) break;
                dp[i] = min(dp[i], dp[prev] + costs[i - 1] + (long long)k * k);
            }
        }

        return (int)dp[n];
    }
};