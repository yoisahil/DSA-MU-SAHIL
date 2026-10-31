class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<array<int, 2>>> memo;

    int dfs(int i, int j, int d, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (memo[i][j][d] != -1) return memo[i][j][d];

        long long res = 0;
        if (grid[i][j] == 1) {
            // mirror: reflect
            if (d == 0) res = dfs(i + 1, j, 1, grid);   // came moving right -> go down
            else        res = dfs(i, j + 1, 0, grid);   // came moving down  -> go right
        } else {
            res = (long long)dfs(i, j + 1, 0, grid) + dfs(i + 1, j, 1, grid);
        }
        return memo[i][j][d] = res % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<array<int, 2>>(n, {-1, -1}));
        return dfs(0, 0, 0, grid);
    }
};