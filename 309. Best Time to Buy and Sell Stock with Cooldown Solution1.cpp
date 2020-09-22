class Solution {
public:
    // 0: rest
    // 1: bought (could be bought in previous days)
    // 2: sold today
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = INT_MIN;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};
