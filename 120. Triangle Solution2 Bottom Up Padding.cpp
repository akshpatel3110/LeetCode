// Beats 100%
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INT_MAX));
        dp[1][1] = triangle[0][0];
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = min(triangle[i - 1][j - 1] + dp[i - 1][j - 1], triangle[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
        
        return *std::min_element(dp[n].cbegin(), dp[n].cend());
    }
};
