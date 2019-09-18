class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }
                
                if (sum > res) {
                    res = sum;
                }
            }
        }
        return res;
    }
};
