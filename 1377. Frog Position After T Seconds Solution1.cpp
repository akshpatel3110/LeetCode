class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        for (auto & e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(1, t, target, 1, -1, g);
    }
    
    double dfs(int u, int t, int target, double p, int parent,
               const vector<vector<int>> & g) {
        if (t == 0) {
            if (u == target) return p;
            return 0;
        }
        
        int num_child = g[u].size();
        if (u != 1)
            --num_child;
        
        if (num_child == 0) {
            if (u == target) return p;
            return 0;
        }
        
        double res = 0;
        for (auto n : g[u]) {
            if (n != parent)
                res = max(res, dfs(n, t - 1, target, p / num_child, u, g));
        }
        return res;
    }
};
