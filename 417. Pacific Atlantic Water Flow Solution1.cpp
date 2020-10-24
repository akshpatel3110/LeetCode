class Solution {
public:
    int m, n;
    vector<vector<int>> state;
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    
    void dfs(int x, int y, int t, vector<vector<int>>& matrix) {
        if (state[x][y] & t) return;
        state[x][y] |= t;
        for (int d = 0; d < 4; ++d) {
            int i = x + dx[d], j = y + dy[d];
            if (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] >= matrix[x][y])
                dfs(i, j, t, matrix);
        }
    }
    
    // Time: O(mn)
    // Space: O(mn)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        state = vector<vector<int>>(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) dfs(i, 0, 1, matrix);
        for (int j = 0; j < n; ++j) dfs(0, j, 1, matrix);
        for (int i = 0; i < m; ++i) dfs(i, n - 1, 2, matrix);
        for (int j = 0; j < n; ++j) dfs(m - 1, j, 2, matrix);
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (state[i][j] == 3)
                    res.push_back({i, j});
        return res;
    }
};
