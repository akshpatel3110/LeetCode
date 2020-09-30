class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    
    int dfs(int x, int y, const vector<vector<int>>& matrix) {
        auto & v = dp[x][y];
        if (v != -1) return v;
        v = 1;
        for (int d = 0; d < 4; ++d) {
            int i = x + dx[d], j = y + dy[d];
            if (i >= 0 && i < m && j >= 0 && j < n && matrix[x][y] > matrix[i][j]) // < to >
                v = max(v, dfs(i, j, matrix) + 1);
        }
        return v;
    }
    
    // Time: O(mn)
    // Space: O(mn)
    // dp[i][j]: the LIP ending at matrix[i][j]
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int res = 0;
        for (int x = 0; x < m; ++x)
            for (int y = 0; y < n; ++y)
                res = max(res, dfs(x, y, matrix));
        return res;
    }
};
