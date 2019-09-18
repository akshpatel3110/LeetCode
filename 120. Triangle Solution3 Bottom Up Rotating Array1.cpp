class Solution {
public:
    // change i to 1 and i - 1 to 0 for dp
    // dp[1] is always the front
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[1][j] = triangle[i][j] + dp[0][j];
                } else if (j == i) {
                    dp[1][j] = triangle[i][j] + dp[0][j - 1];
                } else {
                    dp[1][j] = min(triangle[i][j] + dp[0][j - 1], triangle[i][j] + dp[0][j]);
                }
            }
            std::swap(dp[0], dp[1]);
        }
        
        // Here the front dp[1] is swapped to dp[0]
        return *std::min_element(dp[0].cbegin(), dp[0].cend());
    }
};
