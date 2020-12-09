class Solution {
public:
    // 求方案数不能枚举第一维是amount(重量), 不然会导致重复计算方案
    // Time: O(mn)
    // Space: O(m)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
