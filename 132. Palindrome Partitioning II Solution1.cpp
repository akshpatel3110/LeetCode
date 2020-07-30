class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n ^ 2)
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            dp[i][i] = true;
            dp[i - 1][i] = (s[i - 1] == s[i]);
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1] == 1);
            }
        }
        
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // the last cut is from s[j - 1] to s[i - 1]
            for (int j = 1; j <= i; ++j) {
                if (dp[j - 1][i - 1])
                    f[i] = min(f[i], f[j - 1] + 1);
            }
        }
        return f[n] - 1;
    }
};
