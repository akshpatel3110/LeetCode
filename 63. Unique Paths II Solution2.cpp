class Solution {
public:
    /*  input
        [
          [0,0,0],
          [0,1,0],
          [0,0,0]
        ]
        
        dp
        [
          [0,0,0],
          [0,0,0],
          [0,0,0]
        ]
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    continue; // the value is 0 by default
                
                if (i == 0 && j == 0)
                    dp[0][0] = 1;
                    
                if (i > 0) 
                    dp[i][j] += dp[i - 1][j];
    
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
