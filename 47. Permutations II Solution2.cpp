class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); // true if path[i] is used
        dfs(0, 0, nums, res, path, used);
        return res;
    }
    
    // cur is the index to nums
    void dfs(int cur_num, int start_pos, const vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used)
    {
        if (cur_num == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible positions for current number
        for (int i = start_pos; i < path.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path[i] = nums[cur_num];
                
                // keep order for the same number
                if (cur_num + 1 < nums.size() && nums[cur_num + 1] == nums[cur_num]) {
                    dfs(cur_num + 1, i + 1, nums, res, path, used);
                } else {
                    dfs(cur_num + 1, 0, nums, res, path, used);
                }
                // restore for used, no need to restore path because it will be overwritten in the next iteration
                used[i] = false;
            }
        }
    }
};
