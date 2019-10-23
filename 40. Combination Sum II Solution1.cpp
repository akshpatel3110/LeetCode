class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        return res;
    }
    
private:
    void dfs(const vector<int>& candidates, int target, int idx, vector<vector<int>> & res, vector<int> & path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) 
                return;
            
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, res, path);
            path.pop_back();
        }        
    }
};
