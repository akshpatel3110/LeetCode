class Solution {
public:
    // multisource bfs
    // Time: O(mn)
    // Space: O(mn) for queue
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = t.first + dx[d], y = t.second + dy[d];
                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1) {
                    dist[x][y] = dist[t.first][t.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return dist;
    }
};
