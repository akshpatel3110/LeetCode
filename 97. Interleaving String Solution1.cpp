class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (s3.size() != m + n)
            return false;
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j) {
                if (!i && !j) {
                    dp[i][j] = true;
                } else {
                    if (i && s1[i - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i - 1][j];
                    
                    if (j && s2[j - 1] == s3[i + j - 1])
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        return dp[m][n];
    }
};
