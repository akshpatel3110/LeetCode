class Solution {
public:
    unordered_map<string, unordered_map<string, double>> g;
    
    // Time: O(q * n ^ 2)
    // Space: O(n)
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            auto a = equations[i][0], b = equations[i][1];
            auto c = values[i];
            g[a][b] = c, g[b][a] = 1 / c;
        }
        
        for (auto q : queries) {
            unordered_set<string> visited;
            double t = dfs(q[0], q[1], visited);
            if (t > 0.0) res.push_back(t);
            else res.push_back(-1.0);
        }
        return res;
    }
    
    double dfs(const string & x, const string & y, unordered_set<string> & visited) {
        if (g[x].count(y)) return g[x][y];
        for (auto & ne : g[x]) {
            if (visited.count(ne.first)) continue;
            visited.insert(ne.first);
            double t = dfs(ne.first, y, visited);
            if (t > 0.0) return t * ne.second;
        }
        return -1.0;
    }
};
