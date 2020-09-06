class Solution {
public:
    // Time: O(C(9, k)) * k
    // Space: ignore res, O(k)
    
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
    
    void dfs(int start, int k, int n) {
        if (!k) {
            if (!n) {
                res.push_back(path);
            }
            return;
        }
        
        // i, i + 1, ... 9
        // 9 - i + 1 >= k
        for (int i = start; i <= 10 - k && i <= n; ++i) {
            path.push_back(i);
            dfs(i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
};
