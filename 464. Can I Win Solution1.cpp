class Solution {
public:
    int n;
    int total;
    vector<int> dp;
    
    bool canIWin(int _n, int _total) {
        n = _n;
        total = _total;
        if (n * (n + 1) < total * 2) return false;
        dp.resize(1 << (n + 1), -1);
        return dfs(0, 0);
    }
    
    // Time: O(2 ^ n)
    // Space: O(2 ^ n)
    bool dfs(int u, int sum) {
        if (dp[u] != -1) return dp[u];
        
        for (int i = 1; i <= n; ++i) {
            if (u >> i & 1) continue;
            if (sum + i >= total) return dp[u] = 1;
            if (dfs(u + (1 << i), sum + i) == 0) return dp[u] = 1;
        }
        return dp[u] = 0;
    }
};
