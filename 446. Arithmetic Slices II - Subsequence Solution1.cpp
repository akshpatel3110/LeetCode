class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n ^ 2)
    int numberOfArithmeticSlices(vector<int>& A) {
        using LL = long long;
        int n = A.size();
        vector<unordered_map<LL, int>> dp(n);
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < i; ++k) {
                LL j = (LL)A[i] - A[k];
                auto it = dp[k].find(j);
                int t = 0;
                if (it != dp[k].end()) {
                    t = it->second;
                    res += t;
                }
                dp[i][j] += t + 1;
            }
        return res;
    }
};
