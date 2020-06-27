class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
            
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j] == '*') {
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j];
                } else {
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
                }
            }
        }
        return f[m][n];
    }
};
