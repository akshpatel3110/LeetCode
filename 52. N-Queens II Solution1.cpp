class Solution {
public:
    // Time: O(n!)
    // Space: O(n)
    int totalNQueens(int n) {
        vector<bool> col(n), dg(2 * n - 1), adg(2 * n - 1);
        function<int(int)> dfs = [&](int i) {
            if (i == n)
                return 1;
            
            int res = 0;
            for (int j = 0; j < n; ++j) {
                if (!col[j] && !dg[i - j + n] && !adg[i + j]) {
                    col[j] = dg[i - j + n] = adg[i + j] = true;
                    res += dfs(i + 1);
                    col[j] = dg[i - j + n] = adg[i + j] = false;
                }
            }
            return res;
        };
        return dfs(0);
    }
};
