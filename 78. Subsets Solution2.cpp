class Solution {
public:
    // Time: O(n * 2 ^ (n + 1))
    // Space: path and dfs stack O(n + (n + 1)) = O(n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, path, res, nums);
        return res;
    }
    
    void dfs(int i, vector<int> & path, vector<vector<int>> & res, const vector<int> & nums) {
        if (i == nums.size()) {
            res.push_back(path);
            return;
        }
        
        // not choose nums[i], no need to restore
        dfs(i + 1, path, res, nums);
        
        // choose nums[i]
        path.push_back(nums[i]);
        dfs(i + 1, path, res, nums);
        path.pop_back(); // restore
    }
};
