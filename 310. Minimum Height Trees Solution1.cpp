class Solution {
public:
    vector<vector<int>> g;
    vector<int> d1, d2, p1, up;

    // use child info to calculate father info
    void dfs_1(int u, int father) {
        for (int x: g[u]) {
            if (x == father) continue;
            dfs_1(x, u);
            int d = d1[x] + 1;
            if (d >= d1[u]) {
                d2[u] = d1[u], d1[u] = d;
                p1[u] = x;
            } else if (d > d2[u]) {
                d2[u] = d;
            }
        }
    }

    // a graph traversal, use father info to calculate child info 
    void dfs_2(int u, int father) {
        for (int x: g[u]) {
            if (x == father) continue;
            if (p1[u] == x) up[x] = max(up[u], d2[u]) + 1;
            else up[x] = max(up[u], d1[u]) + 1;
            dfs_2(x, u);
        }
    }
    
    // Time: O(n)
    // Space: O(n)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        d1 = d2 = p1 = up = vector<int>(n);
        for (auto & e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs_1(0, -1);
        dfs_2(0, -1);

        int min_d = n + 1;
        for (int i = 0; i < n; ++i) 
            min_d = min(min_d, max(up[i], d1[i]));
        
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (max(up[i], d1[i]) == min_d)
                res.push_back(i);
        
        return res;       
    }
};
