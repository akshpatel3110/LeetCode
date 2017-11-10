class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2) {
            return 0;
        }
        
        int res = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        size_t i = 0;
        while (i < nums.size() - 2) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (abs(sum - target) < abs(res - target))
                    res = sum;
                
                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    return res;
                }
            }
            
            int curNum = nums[i];
            while (i < nums.size() - 2 && nums[i] == curNum)
                ++i;
        }
        
        return res;        
    }
};
