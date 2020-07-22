class Solution {
public:
    // Time O(k ^ 2)
    // Space: O(k)
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(2, vector<int>(rowIndex + 1));
        for (int i = 0; i <= rowIndex; ++i) {
            dp[i & 1][0] = dp[i & 1][i] = 1;
            for (int j = 1; j < i; ++j)
                dp[i & 1][j] = dp[i - 1 & 1][j - 1] + dp[i - 1 & 1][j]; 
        }
        return dp[rowIndex & 1];
    }
};
