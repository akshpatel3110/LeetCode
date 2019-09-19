class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); // true if path[i] is used
        dfs(0, nums, res, path, used);
        return res;
    }
    
    // cur is the index to nums
    void dfs(int cur_num, const vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used)
    {
        if (cur_num == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible positions for current number
        for (int i = 0 ; i < path.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path[i] = nums[cur_num];
                dfs(cur_num + 1, nums, res, path, used);
                // restore for used, no need to restore path because it will be overwritten in the next iteration
                used[i] = false;
            }
        }
    }
};
