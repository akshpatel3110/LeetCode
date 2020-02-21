class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        
        int l = 0, r = nums.size() - 1;
        while (r > 0 && nums[r] == nums[0]) 
            --r;
        
        int end_val = nums[r];
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] <= end_val)
                r = m;
            else 
                l = m + 1;
        }
        return nums[l];
    }
};
