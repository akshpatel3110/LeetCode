class Solution {
public:
    // Time: O(m * n)
    // Space: O(min(m, n))
    int uniquePaths(int m, int n) {
        // ensure n is smaller to save space
        if (n > m) {
            std::swap(n, m);
        }
        
        vector<vector<int>> dp(2, vector<int>(n, 1)); // 0-th row and 0-th column should be one
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[1][j] = dp[0][j] + dp[1][j-1]; 
            }
            std::swap(dp[0], dp[1]);
        }
        return dp[0][n - 1];
    }
};
