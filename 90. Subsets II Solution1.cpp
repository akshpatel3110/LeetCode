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
    
   void dfs(int idx, vector<int> & path, vector<vector<int>> & res, const vector<int> & nums) {
        res.push_back(path);
        
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) // skip the same number at a certain depth
                continue;
            
            path.push_back(nums[i]);
            dfs(i + 1, path, res, nums);
            path.pop_back();
        }
    }
};
