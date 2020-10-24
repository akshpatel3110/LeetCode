class Solution {
public:
    struct cell {
        int h, x, y;
        bool operator < (const cell & rhs) const {
            return h > rhs.h;
        }
    };
    
    // Time: O(mnlog(mn))
    // Space: O(mn)
    int trapRainWater(vector<vector<int>>& h) {
        if (h.empty() || h[0].empty()) return 0;
        int m = h.size(), n = h[0].size();
        priority_queue<cell> heap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            visited[i][0] = visited[i][n - 1] = true;
            heap.push({h[i][0], i, 0});
            heap.push({h[i][n - 1], i, n - 1});
        }
        
        for (int j = 1; j < n - 1; ++j) {
            visited[0][j] = visited[m - 1][j] = true;
            heap.push({h[0][j], 0, j});
            heap.push({h[m - 1][j], m - 1, j});
        }
        
        int res = 0;
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            res += t.h - h[t.x][t.y];
            for (int d = 0; d < 4; ++d) {
                int i = t.x + dx[d], j = t.y + dy[d];
                if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                    heap.push({max(h[i][j], t.h), i, j});   
                    visited[i][j] = true;
                }
            }
        }
        return res;
    }
};
