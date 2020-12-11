class Solution {
public:
    // state compression dp
    // dp[s]: number of beautiful arrangement if
    // ith (i starts from 0) number is 1 in s, then number i + 1 is used
    // ith number is 0 in s, then number i + 1 is not used
    // used numbers fill positions with an order: lower to higher
    // Time: O(2 ^ n * n)
    // Space: O(2 ^ n)
    int countArrangement(int N) {
        vector<int> dp(1 << N);
        dp[0] = 1;
        for (int s = 0; s < (1 << N); ++s) {
            int tot = 0; // total number used in state s 
            for (int i = 0; i < N; ++i)
                if (s >> i & 1)
                    ++tot;
            
            // enumerate possible numbers in position k + 1
            for (int i = 0; i < N; ++i) {
                if (!(s >> i & 1)) {
                    if ((tot + 1) % (i + 1) == 0 || (i + 1) % (tot + 1) == 0)
                        dp[s | 1 << i] += dp[s];
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};
