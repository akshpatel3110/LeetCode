class Solution {
public:
    unordered_map<string, multiset<string>> g;
    vector<string> res;
    
    // Time: O(vlogv)
    // Space: O(e)
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto & e : tickets)
            g[e[0]].insert(e[1]);
        
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(const string & u) {
        while (g[u].size()) {
            auto ver = *g[u].begin();
            g[u].erase(g[u].begin()); // each edge should be visited at most once
            dfs(ver);
        }
        res.push_back(u);
    }
};
