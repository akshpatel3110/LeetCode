class Solution {
public:
    // Time: O(2 ^ n)
    // Space: path + dfs stack O(n)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, path, res, nums);
        return res;
    }
    
    void dfs(int idx, vector<int> & path, vector<vector<int>> & res, const vector<int> & nums) {
        res.push_back(path);
        
        for (int i = idx; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(i + 1, path, res, nums);
            path.pop_back();
        }
    }
};
