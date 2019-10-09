class Solution {
public:
    // Time: O(m * n)
    // Space: O(min(m, n))
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        
        int n = obstacleGrid[0].size();
        bool swap = false;
        if (n > m) {
            std::swap(m, n);
            swap = true;
        }
            
        vector<vector<long long>> dp(2, vector<long long>(n, 0));        
        for (int i = 0; i < m; ++i) {
            // ensure dp[i & 1] is all 0 since we have +=, otherwise we might include the previous non-zero value
            std::fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
            for (int j = 0; j < n; ++j) {
                if ((!swap && obstacleGrid[i][j] == 1) || (swap && obstacleGrid[j][i] == 1)) {
                    continue;
                }
                
                if (i == 0 && j == 0)
                    dp[0 & 1][0] = 1;
                    
                if (i > 0) 
                    dp[i & 1][j] += dp[i - 1 & 1][j];
    
                if (j > 0)
                    dp[i & 1][j] += dp[i & 1][j - 1];
            }
        }
        return dp[m - 1 & 1][n - 1];
    }
};
