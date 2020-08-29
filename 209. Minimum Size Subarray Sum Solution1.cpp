class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), res = n + 1, sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            sum += nums[i];
            
            // move j until the sub array sum from j to i is < s
            while (j <= i && sum >= s) {
                sum -= nums[j];
                ++j;
            }
            
            // j - 1 to i will be the min size subarray with sum >= s
            if (j >= 1) {
                res = min(res, i - (j - 1) + 1);
            }
        }
        
        return res == n + 1 ? 0 : res;  
    }
};
