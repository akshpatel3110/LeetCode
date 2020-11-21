class Solution {
public:
    // Time: O(mn)
    // Space: O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        int res = 0;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int i = x + dx[d], j = y + dy[d];
                        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
                            ++res;
                    }
                }
            }
        }
        return res;
    }
};
