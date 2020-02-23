class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r + 1 >> 1;
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
        return nums[l] == target ? l : -1;
    }
};
