class Solution {
public:
    // Time: O(mn)
    // Space: O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& w) {
        vector<int> res;
        if (w.empty() || w[0].empty()) return res;
        int m = w.size(), n = w[0].size();
        for (int s = 0; s < m + n - 1; ++s) {
            if (s % 2 == 0) {
                for (int i = min(s, m - 1); i >= max(s - n + 1, 0); --i)
                    res.push_back(w[i][s - i]);
            } else {
                for (int i = max(s - n + 1, 0); i <= min(s, m - 1); ++i)
                    res.push_back(w[i][s - i]);
            }
        }
        return res;
    }
};
