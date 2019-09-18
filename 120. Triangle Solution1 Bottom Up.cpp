class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == i) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
                }
            }
        }
        
        return *std::min_element(dp[n - 1].cbegin(), dp[n - 1].cend());
    }
};
