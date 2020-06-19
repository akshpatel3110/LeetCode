class Solution {
public:
    // Time: O(mn)
    // Space: O(mn)
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> st(m, vector<bool>(n));
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);
        dist[0][0] = 0;
        
        vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
        while (q.size()) {
            auto t = q.front();
            q.pop_front();
            
            int x = t.first, y = t.second;
            if (st[x][y])
                continue;
            
            st[x][y] = true;
            for (int d = 0; d < 4; ++d) {
                int i = x + dx[d], j = y + dy[d];
                if (i < 0 || i >= m || j < 0 || j >= n)
                    continue;
                
                int w = grid[x][y] - 1 != d;
                if (dist[i][j] > dist[x][y] + w) {
                    dist[i][j] = dist[x][y] + w;
                    if (w == 0)
                        q.emplace_front(i, j);
                    else
                        q.emplace_back(i, j);
                }
            }
        }
        return dist.back().back();
    }
};
