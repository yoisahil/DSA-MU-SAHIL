class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // K = smallest power of two greater than the max value
        int mx = 0;
        for (auto& row : grid)
            for (int v : row) mx = max(mx, v);
        int K = 1;
        while (K <= mx) K <<= 1;

        // dp[j] = set of reachable XOR values at the current row, column j
        vector<vector<char>> dp(n, vector<char>(K, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int g = grid[i][j];
                vector<char> cur(K, 0);

                if (i == 0 && j == 0) {
                    cur[g] = 1;
                } else {
                    for (int x = 0; x < K; x++) {
                        bool reach = (i > 0 && dp[j][x]) ||      // from above
                                     (j > 0 && dp[j - 1][x]);    // from left
                        if (reach) cur[x ^ g] = 1;
                    }
                }
                dp[j] = move(cur);
            }
        }

        for (int x = 0; x < K; x++)
            if (dp[n - 1][x]) return x;
        return -1;
    }
};