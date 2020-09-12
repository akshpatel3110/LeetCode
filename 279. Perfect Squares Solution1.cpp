class Solution {
public:
    // Time: O(1 + sqrt(1) + sqrt(2) + .. + sqrt(n) = n * sqrt(n))
    // Space: O(n)
    // Unbounded knapsack problem
    // we have sqrt(n) items, each item has value of 1, each item can be chosen unlimited number of times
    // total weight is n, we would like to minimize total value.
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        
        return dp[n];
    }
};
