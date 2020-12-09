class Solution {
public:
    bool check(const string & a, const string & b) {
        int i = 0, j = 0;
        while (j < b.size()) {
            if (a[i] == b[j]) ++i;
            ++j;
        }
        return i == a.size();
    }
    
    // Time: O(m ^ 2 * n)
    // Space: O(1)
    int findLUSlength(vector<string>& strs) {
        int res = -1, n = strs.size();
        for (int i = 0; i < n; ++i) {
            bool is_sub = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (check(strs[i], strs[j])) {
                    is_sub = true;
                    break;
                }
            }
            if (!is_sub) res = max(res, (int)strs[i].size());
        }
        return res;
    }
};
