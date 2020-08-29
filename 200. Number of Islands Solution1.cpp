class Solution {
public:
    int m;
    int n;
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    
    // Time: O(mn) 
    // Space: O(mn) for dfs stack
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        for (int x = 0; x < m; ++x)
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == '1') {
                    dfs(x, y, grid);
                    ++res;
                }
            }
        return res;
    }
    
    void dfs(int x, int y, vector<vector<char>> & grid) {
        grid[x][y] = '0';
        for (int d = 0; d < 4; ++d) {
            int i = x + dx[d], j = y + dy[d];
            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1')
                dfs(i, j, grid);
        }
    }
};
