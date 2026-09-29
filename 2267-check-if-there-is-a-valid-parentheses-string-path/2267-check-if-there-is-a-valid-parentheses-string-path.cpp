class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {
        if (balance < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move down
        if (i + 1 < n) {
            int b = balance + (grid[i + 1][j] == '(' ? 1 : -1);

            if (dfs(grid, i + 1, j, b))
                return dp[i][j][balance] = 1;
        }

        // Move right
        if (j + 1 < m) {
            int b = balance + (grid[i][j + 1] == '(' ? 1 : -1);

            if (dfs(grid, i, j + 1, b))
                return dp[i][j][balance] = 1;
        }

        return dp[i][j][balance] = 0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m) % 2 == 0)
            return false;

        // First must be '(' and last must be ')'
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));

        return dfs(grid, 0, 0, 1);
    }
};