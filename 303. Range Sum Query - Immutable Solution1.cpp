class NumArray {
public:
    vector<int> dp;
    
    NumArray(vector<int>& nums) {
        dp.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    // Time: O(1)
    // Space: O(n)
    int sumRange(int i, int j) {
        ++i;
        ++j;
        return dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
