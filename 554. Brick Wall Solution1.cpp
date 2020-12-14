class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        for (auto & line : wall) {
            for (int i = 0, s = 0; i < (int)line.size() - 1; ++i) {
                s += line[i];
                ++hash[s];
            }
        }
        
        int edges = 0;
        for (auto [k, v] : hash)
            edges = max(edges, v);
        return wall.size() - edges;
    }
};
