class Solution {
public:
    // Time: O(2 ^ n)
    // Space: O(n)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // put same numbers together
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
        
        // calculate the numbers of nums[i]
        int k = 0;
        while (i + k < nums.size() && nums[i + k] == nums[i])
            ++k;
        
        // nums[i] can be chosen 0 to k times
        for (int j = 0; j <= k; ++j) {
            dfs(i + k, path, res, nums);
            path.push_back(nums[i]);
        }
        
        // restore
        path.erase(path.end() - k - 1, path.end());
        
    }
};
