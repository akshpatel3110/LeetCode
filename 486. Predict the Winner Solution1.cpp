class Solution {
public:
    // dp[i][j]: max score diff the first player can outscore the second player in interval [i, j]
    // Time: O(n ^ 2)
    // Space: O(n ^ 2)
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(-dp[i + 1][j] + nums[i], -dp[i][j - 1] + nums[j]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
