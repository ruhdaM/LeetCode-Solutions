class Solution {
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> g;
    vector<vector<array<int, 2>>> memo;

    // dir = 0 -> arrived moving right, dir = 1 -> arrived moving down
    int dfs(int i, int j, int dir) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;

        int& res = memo[i][j][dir];
        if (res != -1)
            return res;

        if (g[i][j] == 1) {
            // mirror: right -> down, down -> right
            res = (dir == 0) ? dfs(i + 1, j, 1) : dfs(i, j + 1, 0);
        } else {
            res = (dfs(i, j + 1, 0) + dfs(i + 1, j, 1)) % MOD;
        }
        return res;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<array<int, 2>>(n, {-1, -1}));
        return dfs(0, 0, 0);
    }
};