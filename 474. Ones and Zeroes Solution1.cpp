class Solution {
public:
    // two dimensional 0-1 knapsack problem
    // Time: O(len(strs) * (m - zeros) * (n - ones))
    // Space: O(mn)
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto & str : strs) {
            int zeros = 0, ones = 0;
            for (auto c : str)
                if (c == '0') ++zeros;
                else ++ones;
            for (int i = m; i >= zeros; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
        return dp[m][n];
    }
};
