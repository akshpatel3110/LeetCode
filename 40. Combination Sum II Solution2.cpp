/*
p = target / min(candidates[i]) + 1
Time: O(C(n, 1) + C(n, 2) + C(n, 3) + … + C(n, p))
Space: O(path + recursion stack) = O(p)
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, path);
        return vector<vector<int>>(res.begin(), res.end());
    }
    
private:
    void dfs(const vector<int>& candidates, int target, int idx, set<vector<int>> & res, vector<int> & path) {
        if (target == 0) {
            res.insert(path);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] > target) 
                return;

            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, res, path);
            path.pop_back();
        }        
    }
};
