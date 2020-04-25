class Solution {
public:
    // When (n - 1) & (K - 1) != 0, we can merge into one pile
    // dp[i][j]: the min cost to merge stones from i to j into the least number of piles
    // divide dp[i][j] according to what is the last stone index of the first pile,
    // which can only be i, i + k - 1, i + 2(k - 1) ...
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1))
            return -1;
            
        vector<int> sums(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            sums[i] = sums[i - 1] + stones[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(n));

        function<int(int, int)> dfs = [&](int i, int j) {
            if (j - i + 1 < K)
                return 0;
            
            if (dp[i][j])
                return dp[i][j];
            
            int res = INT_MAX;
            for (int t = i; t < j; t += K - 1) {
                res = min(res, dfs(i, t) + dfs(t + 1, j));
            }
            if ((j - i) % (K - 1) == 0)
                res += sums[j + 1] - sums[i];
            
            return dp[i][j] = res; 
        };
        return dfs(0, n - 1);
    }
};
