class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> in_d(n);
        for (auto & p : prerequisites) {
            g[p[1]].push_back(p[0]);
            ++in_d[p[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_d[i] == 0)
                q.push(i);
        }
        
        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (auto neigh : g[t]) {
                if (--in_d[neigh] == 0)
                    q.push(neigh);
            }
        }
        if (res.size() < n)
            res = {};
        
        return res;        
    }
};
