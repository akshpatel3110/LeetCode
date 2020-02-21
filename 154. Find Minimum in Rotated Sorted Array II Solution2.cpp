class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (long long)r >> 1;
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m + 1;
            else
                --r;
        }
        return nums[l];
    }
};
