class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] == target)
                return true;
            
            if (nums[m] == nums[r]) {
                --r;
                continue;
            }
            
            if (target <= nums[r]) {
                if (nums[m] >= target && nums[m] <= nums[r])
                    r = m;
                else
                    l = m + 1;
            } else {
                if (nums[m] >= target || nums[m] <= nums[r])
                    r = m;
                else
                    l = m + 1;
            }
        }
        return nums[l] == target ? true : false;
    }
};
