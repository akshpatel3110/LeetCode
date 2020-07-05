class Solution {
public:
    // Time: O(n!)
    // Space: O(n ^ 2)
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n), dg(2 * n - 1), adg(2 * n - 1);
        vector<vector<string>> res;
        vector<string> path(n, string(n, '.'));
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.push_back(path);
                return;
            }
            
            for (int j = 0; j < n; ++j) {
                if (!col[j] && !dg[j - i + n] && !adg[i + j]) {
                    col[j] = dg[j - i + n] = adg[i + j] = true;
                    path[i][j] = 'Q';
                    dfs(i + 1);
                    path[i][j] = '.';
                    col[j] = dg[j - i + n] = adg[i + j] = false;                    
                }
            }
        
        };
        dfs(0);
        return res;
    }
};
