class Solution {
public:
    int n;
    vector<int> dp;

    // Time: O(n)
    // Space: O(n)
    int candy(vector<int>& ratings) {
        n = ratings.size();
        dp.resize(n, -1);
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += dfs(i, ratings);
        return res;
    }
    
    int dfs(int i, const vector<int> & ratings) {
        if (dp[i] != -1)
            return dp[i];
        
        dp[i] = 1;
        if (i && ratings[i - 1] < ratings[i])
            dp[i] = max(dp[i], dfs(i - 1, ratings) + 1);
        
        if (i + 1 < n && ratings[i + 1] < ratings[i])
            dp[i] = max(dp[i], dfs(i + 1, ratings) + 1);
        
        return dp[i];
    }
};
