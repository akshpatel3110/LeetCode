class Solution {
public:
    // Unbounded knapsack problem: each item has value 1, weight is demonination of the coin
    // total weight is amount, we would like to minimize the total value.
    // Time: O(amount * (size of coins))
    // Space: O(amount)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto w : coins)
            for (int j = w; j <= amount; ++j)
                dp[j] = min(dp[j], dp[j - w] + 1);
        return (dp.back() == amount + 1 ? -1 : dp.back());
    }
};
