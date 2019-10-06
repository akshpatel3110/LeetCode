class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(nums, res, path, used);
        return res;
    }
    
    void dfs(const vector<int> & nums, vector<vector<int>> & res, vector<int> & path, vector<bool> & used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // enumerate possible numbers for current position
        for (int i = 0 ; i < nums.size(); ++i) {
            if (!used[i]) {
                // skip same number for current position
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, res, path, used);
                // restore
                path.pop_back();
                used[i] = false;
            }
        }
    }
};
