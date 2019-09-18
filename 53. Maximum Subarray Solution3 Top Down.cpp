class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        dfs(nums.size() - 1, nums, res);
        return res;
    }
    
    int dfs(int cur, vector<int>& nums, int & res) {
        if (cur == 0)
            return nums[0];
        
        int prev_sum = dfs(cur - 1, nums, res);
        int cur_sum = max(prev_sum + nums[cur], nums[cur]);
        if (cur_sum > res)
            res = cur_sum;
            
        return cur_sum;
    }
};
