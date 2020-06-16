class Solution {
public:
    // Time: O(n ^ 3)
    // Space: O(n ^ 2)
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> g(n, vector<bool>(n));
        for (const auto & p : prerequisites)
            g[p[0]][p[1]] = true;
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (g[i][k] && g[k][j])
                        g[i][j] = true;
        
        vector<bool> res;
        for (const auto & q : queries)
            res.push_back(g[q[0]][q[1]]);

        return res;
    }
};
