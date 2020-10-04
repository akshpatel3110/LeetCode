class Solution {
public:
    // Time: O(n * target)
    // Space: O(target)
    // follow up: if negative numbers are allowed in nums, we might have infinite combinations
    // for a given target. We can add a limitation on how many times the negative number can be used.
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= nums[j])
                    dp[i] = (dp[i] + dp[i - nums[j]]) % INT_MAX;
            }
        }
        return dp[target];
    }
};
