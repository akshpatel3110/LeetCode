class Solution {
public:
    // Time: O(n)
    // Space: O(n + h) == O(n)
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g(n);
        for (auto e : connections) {
            g[e[0]].emplace_back(e[1], true);
            g[e[1]].emplace_back(e[0], false);
        }
        return dfs(0, -1, g);
    }
    
    int dfs(int u, int parent, vector<vector<pair<int, bool>>> & g) {
        int res = 0;
        for (const auto & e : g[u]) {
            if (e.first == parent)
                continue;
            res += dfs(e.first, u, g) + (e.second == true);
        }
        return res;
    }
};
