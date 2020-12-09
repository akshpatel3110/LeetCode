class Solution {
public:
    // similar to 0-1 knapsack, add an offset for sum to simplify definition of dp vector
    // Time: O(n * sum)
    // Space: O(n * sum)
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        
        if (S < -sum || S > sum) 
            return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1));
        dp[0][0 + sum] = 1; // no number and sum is zero has 1 way to achieve
        for (int i = 1; i <= n; ++i)
            for (int j = -sum; j <= sum; ++j) {
                if (j - nums[i - 1] >= -sum) // think about the original vector without offset for this if
                    dp[i][j + sum] += dp[i - 1][j - nums[i - 1] + sum];
                if (j + nums[i - 1] <= sum)
                    dp[i][j + sum] += dp[i - 1][j + nums[i - 1] + sum];
            }
        return dp[n][S + sum];
    }
};
