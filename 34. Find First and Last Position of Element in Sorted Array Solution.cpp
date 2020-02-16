class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty())
            return res;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        
        if (nums[l] != target)
            return res;
        
        res[0] = l;
        r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r + 1 >> 1;
            if (nums[m] <= target)
                l = m;
            else
                r = m - 1;
        }
        res[1] = l;
        return res;
    }
};
