class Solution {
public:\
    // 0 1 knapsack boolean problem
    // each item has weight of nums[i], total weight is sum / 2.
    // There is no value for an item here.
    // Time: O(sum * n)
    // Space: O(sum)
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto x : nums)
            sum += x;
        
        if (sum % 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (auto x : nums)
            for (int j = sum; j >= x; --j)
                if (dp[j - x]) dp[j] = true;
        
        return dp[sum];
    }
};
