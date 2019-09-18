class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int dp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp = max(dp + nums[i], nums[i]);
            if (dp > res)
                res = dp;
        }
        return res;

    }
};
