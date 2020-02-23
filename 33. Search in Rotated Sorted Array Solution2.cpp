class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] == target)
                return m;
            
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
        
        // only for nums having one element do we return l
        return nums[l] == target ? l : -1;
    }
};
