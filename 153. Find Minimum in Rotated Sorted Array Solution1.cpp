class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] <= nums.back())
                r = m;
            else
                l = m + 1;
        }
        return nums[l];
    }
};
