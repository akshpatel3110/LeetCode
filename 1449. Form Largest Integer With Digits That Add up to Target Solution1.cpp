class Solution {
public:
    // Time: O(target)
    // Space: O(target)
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<int>> dp(10, vector<int>(target + 1));
            
        for (int i = 1; i <= target; ++i)
            dp[0][i] = INT_MIN;
            
        for (int i = 1; i <= 9; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= cost[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j - cost[i - 1]] + 1);
            }
        }
        
        if (dp[9][target] < 1)
            return "0";
        
        string res;
        for (int i = 9, j = target; i > 0; --i) {
            while (j >= cost[i - 1] && dp[i][j] == dp[i][j - cost[i - 1]] + 1) {
                res += to_string(i);
                j -= cost[i - 1];
            }
        }
        return res;
    }
};
