class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int c = 0;
                    // for each residue group, count palindrome mismatches
                    for (int r = 0; r < d; r++) {
                        int a = i + r;
                        int b = j - d + 1 + r;
                        while (a < b) {
                            if (s[a] != s[b]) c++;
                            a += d;
                            b -= d;
                        }
                    }
                    best = min(best, c);
                }
                cost[i][j] = best;
            }
        }

        // dp[p][i] = min cost to split s[i..n-1] into p substrings
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][n] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (cost[i][j] >= INF || dp[p - 1][j + 1] >= INF) continue;
                    dp[p][i] = min(dp[p][i], cost[i][j] + dp[p - 1][j + 1]);
                }
            }
        }

        return dp[k][0];
    }
};