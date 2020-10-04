class Solution {
public:
    // Time: O(n ^ 2 mlogm)
    // Space: O(mn)
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
        
        int res = INT_MIN;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) {
                set<int> pre; // prefix sums
                pre.insert(0);
                for (int p = 1; p <= m; ++p) {
                    int sp = s[p][j] - s[1 - 1][j] - s[p][i - 1] + s[1 - 1][i - 1]; // (1, i) and (p, j)
                    auto it = pre.lower_bound(sp - k);
                    if (it != pre.end())
                        res = max(res, sp - *it);
                    
                    pre.insert(sp);
                }
            }
        return res;
    }
};
