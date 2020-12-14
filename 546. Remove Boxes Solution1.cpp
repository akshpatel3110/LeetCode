class Solution {
public:
    // Time: O(n ^ 4)
    // Space: O(n ^ 3)
    // f[i][j][k]: max points for intervals [i, j], last step remove k boxes including i
    // g[i][j]: max(f[i][j][k]) for all k
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n + 1, INT_MIN)));
        vector<vector<int>> g(n, vector<int>(n, INT_MIN));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                for (int k = 1; k <= len; ++k) {
                    if (len == 1) f[i][j][k] = 1;
                    else if (k == 1) f[i][j][k] = 1 + g[i + 1][j];
                    else {
                        for (int u = i + 1; u <= j - k + 2; ++u) {
                            if (boxes[i] != boxes[u] || f[u][j][k - 1] == INT_MIN) continue;
                            int t = 0;
                            if (i + 1 <= u - 1) t = g[i + 1][u - 1];
                            f[i][j][k] = max(f[i][j][k], t + f[u][j][k - 1] - (k - 1) * (k - 1) + k * k);
                        }
                    }
                    g[i][j] = max(g[i][j], f[i][j][k]);
                }
            }
        }
        return g[0][n - 1];
    }
};
