class Solution {
public:
    // Time: O(min(m, n))
    // Space: O(mn)
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        bool swap = false;
        if (n > m) {
            std::swap(m, n);
            swap = true;
        }
        
        vector<vector<int>> dp(2, vector<int>(n + 1));
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; ++i) {
            dp[i & 1][0] = i;
            for (int j = 1; j <= n; ++j) {
                if ((!swap && word1[i - 1] == word2[j - 1]) || 
                    (swap && word1[j - 1] == word2[i - 1])) {
                    dp[i & 1][j] = dp[i - 1 & 1][j - 1];
                } else {
                    dp[i & 1][j] = min({dp[i - 1 & 1][j - 1], dp[i - 1 & 1][j], dp[i & 1][j - 1]}) + 1;   
                }
            }
        }
        return dp[m & 1][n];
    }
};
