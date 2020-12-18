class Solution {
public:
    // Time: O(mnN)
    // Space: O(mnN)
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0)
            return 0;
        
        int mod = 1e9 + 7;
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        vector<vector<vector<int>>> f(N, vector<vector<int>>(m, vector<int>(n)));

        for (int x = 0; x < m; ++x) {
            ++f[0][x][0];
            ++f[0][x][n - 1];
        }

        for (int y = 0; y < n; ++y) {
            ++f[0][0][y];
            ++f[0][m - 1][y];
        }

        for (int k = 1; k < N; ++k)
            for (int x = 0; x < m; ++x)
                for (int y = 0; y < n; ++y)
                    for (int d = 0; d < 4; ++d) {
                        int a = x + dx[d], b = y + dy[d];
                        if (a < 0 || a >= m || b < 0 || b >= n)
                            continue;
                        f[k][x][y] = (f[k][x][y] + f[k - 1][a][b]) % mod;
                    }
        
        int res = 0;
        for (int k = 0; k < N; ++k)
            res = (res + f[k][i][j]) % mod;
        return res;      
    }
};
