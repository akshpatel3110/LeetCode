class Solution {
public:
    // Time: ignore push_back, O(C(9, k))
    // Space: ignore res, O(k)
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, k, n, res, path);
        return res;
    }
    
    void dfs(int start, int k, int n, vector<vector<int>> & res, vector<int> & path) {
        if (!k) {
            if (!n)
                res.push_back(path);

            return;
        }
        
        // 9 - i + 1 >= k
        for (int i = start; i <= 10 - k; ++i) {
            if (i > n)
                return;
            
            path.push_back(i);
            dfs(i + 1, k - 1, n - i, res, path);
            path.pop_back();
        }
    }
};
