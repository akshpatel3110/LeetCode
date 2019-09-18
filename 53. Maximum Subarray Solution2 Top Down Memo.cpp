class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        unordered_map<int, int> memo;
        memo[0] = nums[0];
        dfs(nums.size() - 1, nums, res, memo);
        return res;
    }
    
    int dfs(int cur, vector<int>& nums, int & res, unordered_map<int, int> & memo) {
        auto it = memo.find(cur);
        if (it != memo.end()) {
            return it->second;
        }
        
        int prev_sum = dfs(cur - 1, nums, res, memo);
        int cur_sum = max(prev_sum + nums[cur], nums[cur]);
        if (cur_sum > res)
            res = cur_sum;
            
        return memo[cur] = cur_sum;
    }
};
