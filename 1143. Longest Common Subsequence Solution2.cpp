class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == 0 || j == 0)
                return 0;
            
            if (dp[i][j])
                return dp[i][j];
            
            int res = max(dfs(i - 1, j), dfs(i, j - 1));
            if (text1[i - 1] == text2[j - 1])
                res = max(res, dfs(i - 1, j - 1) + 1);
            
            return dp[i][j] = res;
        };
        return dfs(m, n);
    }
};
