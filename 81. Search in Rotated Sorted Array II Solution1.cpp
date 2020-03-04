class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        
        int l = 0, r = nums.size() - 1;
        while (r > 0 && nums[r] == nums[0])
            --r;
        
        while (l < r) {
            int m = l + (long long)r + 1 >> 1;
            if (nums[m] == target)
                return true;
            
            if (target <= nums[r]) {
                if (nums[m] <= target || nums[m] > nums[r])
                    l = m;
                else
                    r = m - 1;
            } else {
                if (nums[m] <= target && nums[m] >= nums[l])
                    l = m;
                else
                    r = m - 1;
            }
        }
        return nums[l] == target ? true : false;
    }
};
