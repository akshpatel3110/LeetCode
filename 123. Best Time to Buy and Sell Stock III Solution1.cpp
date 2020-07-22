class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1);
        for (int i = 1, minp = INT_MAX; i <= n; ++i) {
            dp[i] = max(dp[i - 1], prices[i - 1] - minp);
            minp = min(minp, prices[i - 1]);
        }
        
        int res = 0;
        for (int i = n, maxp = 0; i; --i) {
            res = max(res, dp[i - 1] + maxp - prices[i - 1]);
            maxp = max(maxp, prices[i - 1]);
        }
        return res;
    }
};
