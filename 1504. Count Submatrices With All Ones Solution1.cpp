class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<vector<int>> h(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            stack<pair<int, int>> st;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    h[i][j] = 1;
                    if (i) h[i][j] += h[i - 1][j];
                }
                while (st.size() && h[i][j] <= h[i][st.top().first])
                    st.pop();
                
                int tot = 0;
                if (st.size()) {
                    tot += st.top().second;
                    tot += (j - st.top().first) * h[i][j];
                } else {
                    tot += (j + 1) * h[i][j];
                }
                st.emplace(j, tot);
                res += tot;
            }
        }
        return res;
    }
};
