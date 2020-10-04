class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n)
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }
        return dp[n];
    }
};
