class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || nums.back() < target)
            return nums.size();
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
