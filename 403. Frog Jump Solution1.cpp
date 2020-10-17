class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int, int> hash;
    int n;
    
    // Time: O(n ^ 2)
    // Space: O(n ^ 2)
    int dfs(int i, int j, vector<int>& stones) {
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        dp[i][j] = 0;
        for (int k = max(1, j - 1); k <= min(j + 1, n); ++k) {
            if (hash.count(stones[i] - k)) {
                int t = hash[stones[i] - k];
                if (dfs(t, k, stones)) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
        return dp[i][j];
    }
    
    // dp[i][j]: whether ith stone has can jump j steps, we need another state for "calculated"
    // that is why we need int instead of bool
    bool canCross(vector<int>& stones) {
        n = stones.size();
        
        // nth stone have a max n jump ability
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        for (int i = 0; i < n; ++i)
            hash[stones[i]] = i;
        
        dp[0][1] = 1;
        for (int i = 1; i <= n; ++i)
            if (dfs(n - 1, i, stones))
                return true;
        
        return false;
    }
};
