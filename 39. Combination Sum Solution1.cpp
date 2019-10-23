/*
p = target / min(candidates[i]) + 1
n = size of candidates
C(n, r) = (n + r - 1)! / (n-1)r!
Time: O(C(n, 1) + C(n, 2) + C(n, 3) + … + C(n, p))
Space: O(path + recursion stack) = O(p)
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, path);
            path.pop_back();
        }
    }
};
