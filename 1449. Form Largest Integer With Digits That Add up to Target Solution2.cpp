class Solution {
public:
    // Time: O(target)
    // Space: O(target)
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, INT_MIN);
        
        dp[0] = 0;
        for (int i = 1; i <= 9; ++i)
            for (int j = cost[i - 1]; j <= target; ++j)
                dp[j] = max(dp[j], dp[j - cost[i - 1]] + 1);
        
        if (dp[target] < 1)
            return "0";
        
        string res;
        for (int i = 9, j = target; i > 0; --i) {
            while (j >= cost[i - 1] && dp[j] == dp[j - cost[i - 1]] + 1) {
                res += to_string(i);
                j -= cost[i - 1];
            }
        }
        return res;
    }
};
