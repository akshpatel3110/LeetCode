class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int res = 0;
        for (int i = 0; i < p.size(); ++i) {
            unordered_map<int, int> hash;
            for (int j = 0; j < p.size(); ++j) {
                if (i != j) {
                    int dx = p[i][0] - p[j][0];
                    int dy = p[i][1] - p[j][1];
                    int dist = dx * dx + dy * dy;
                    ++hash[dist];
                }
            }
            for (auto [d, c] : hash)
                res += c * (c - 1);
        }
        return res;
    }
};
