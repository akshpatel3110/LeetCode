class Solution {
public:
    // dp[i][j]: min rotating steps for completing first ith char of key, jth char of ring points to 12:00 (index starts from 0)
    // Time: O(m ^ 2 * n)
    // Space: O(mn)
    int findRotateSteps(string ring, string key) {
        int m = key.size(), n = ring.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; ++j)
            if (key[0] == ring[j])
                dp[0][j] = min(j, n - j) + 1;
        
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (key[i] == ring[j]) {
                    for (int k = 0; k < n; ++k) {
                        if (dp[i - 1][k] != INT_MAX)
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                    }
                }
            }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j)
            res = min(res, dp[m - 1][j]);
        return res;
    }
};
