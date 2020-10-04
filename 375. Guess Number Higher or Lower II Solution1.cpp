class Solution {
public:
    // Time: O(n ^ 3)
    // Space: O(n ^ 2)
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // guess a number between [i, j]
                for (int k = i; k <= j; ++k)
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
            }
        }
        return dp[1][n];
    }
};
