class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(0, nums, res, path, used);
        return res;
    }
    
    // cur_pos is the index to path
    void dfs(int cur_pos, const vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used)
    {
        if (cur_pos == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible numbers for current position
        for (int i = 0 ; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path[cur_pos] = nums[i];
                dfs(cur_pos + 1, nums, res, path, used);
                // restore for used, no need to restore path because it will be overwritten in the next iteration
                used[i] = false;
            }
        }
    }
};
