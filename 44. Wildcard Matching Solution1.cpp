class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        for (int i = 1; i <= n; ++i)
            if (p[i - 1] == '*')
                f[0][i] = f[0][i - 1];
            
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                } else {
                    f[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && f[i - 1][j - 1];
                }
            }
        }
        return f[m][n];
    }
};
