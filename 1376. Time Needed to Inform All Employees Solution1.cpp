class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (i != headID)
                g[manager[i]].push_back(i);
        }
        
        return dfs(headID, g, informTime);
    }
    
    int dfs(int u, const vector<vector<int>> & g,
            vector<int> & informTime) {
        int res = 0;
        for (auto n : g[u])
            res = max(res, dfs(n, g, informTime));
        return res + informTime[u];
    }
};
