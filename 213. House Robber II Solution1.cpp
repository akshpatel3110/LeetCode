class Solution {
public:
    // divide problem based on whether we rob the first house or not
    // Time: O(n)
    // Space: O(n)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(f(nums, 0, n - 2), f(nums, 1, n - 1));
    }
    
    int f(vector<int> & nums, int l, int r) {
        if (l == r) return nums[l];
        vector<int> dp(r - l + 1);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l + 1]);
        for (int i = 2; i < r - l + 1; ++i) {
            dp[i] = max(dp[i - 1], nums[l + i] + dp[i - 2]);
        }
        return dp.back();
    }
};
