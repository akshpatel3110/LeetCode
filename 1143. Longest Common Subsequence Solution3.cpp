class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        bool swap = false;
        if (n > m) {
            std::swap(m, n);
            swap = true;
        }
        vector<vector<int>> dp(2, vector<int>(n + 1));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i & 1][j] = max(dp[i - 1 & 1][j], dp[i & 1][j - 1]);
                if ((!swap && text1[i - 1] == text2[j - 1]) ||
                    (swap && text1[j - 1] == text2[i - 1]))
                    dp[i & 1][j] = max(dp[i & 1][j], dp[i - 1 & 1][j - 1] + 1);
            }
        }
        return dp[m & 1][n];
    }
};
