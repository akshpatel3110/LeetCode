class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> res;
    vector<string> path;
    
    // Time: O((2 ^ n) * n)
    // Space: O(n ^ 2)
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n));
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
        dfs(s, 0);
        return res;
    }
    
    void dfs(const string & s, int u) {
        if (u == s.size()) {
            res.push_back(path);
        } else {
            for (int i = u; i < s.size(); ++i) {
                if (dp[u][i]) {
                    path.push_back(s.substr(u, i - u + 1));
                    dfs(s, i + 1);
                    path.pop_back();
                }
            }
        }
    }
};
