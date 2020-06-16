class Solution {
public:
    // Time: O(m * n ^ 2)
    // Space: O(m * n ^ 2)
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    for (int a = j - 1; a <= j + 1; ++a) {
                        for (int b = k - 1; b <= k + 1; ++b) {
                            if (a < 0 || a >= n || b < 0 || b >= n)
                                continue;
                            
                            int t = dp[i - 1][a][b];
                            if (t == -1)
                                continue;

                            if (j == k)
                                t += grid[i][j];
                            else
                                t += grid[i][j] + grid[i][k];
                            
                            dp[i][j][k] = max(dp[i][j][k], t);
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res = max(res, dp[m - 1][j][k]);
            }
        }
        return res;
    }
};
