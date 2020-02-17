class Solution {
public:
    int findMin(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    int dfs(vector<int>& nums, int l, int r) {
        if (nums[l] <= nums[r]) 
            return nums[l];
        
        int m = l + (long long)r >> 1;
        return min(dfs(nums, l, m), dfs(nums, m + 1, r));
    }
};
