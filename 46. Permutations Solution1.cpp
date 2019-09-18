class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(nums, res, path, used);
        return res;
    }
    
    void dfs(const vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible numbers for current position
        for (int i = 0 ; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, res, path, used);
                // restore for the next possible number for current position
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
