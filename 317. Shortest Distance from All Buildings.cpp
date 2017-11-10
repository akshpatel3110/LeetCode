/*
O(m ^ 2 * n ^ 2) time
O(m * n) space

BFS from all buildings
hit: how many times an empty land has reached
distSum: the sum of all buildings to that empty land


early pruning: return -1 if not all the buildings are connected 

Solution: Pick an empty land reachable from all buildings with the minimum distance sum


*/

class Solution {
    
public:
    int shortestDistance(const vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        int buildings = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    ++buildings;
        
        vector<vector<int>> hit(m, vector<int>(n, 0));
        vector<vector<int>> distSum(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    if (!bfs(i, j, grid, hit, distSum, buildings, m, n))
                        return -1;
        
        int res = INT_MAX;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0 && hit[i][j] == buildings)
                    res = min(res, distSum[i][j]);
        
        return res == INT_MAX? -1 : res;
    }
    
    bool bfs(int startI, int startJ, const vector<vector<int>>& grid, vector<vector<int>>& hit,
             vector<vector<int>>& distSum, int buildings, int m, int n) {
        vector<vector<bool>> visited(m , vector<bool>(n, 0));
        visited[startI][startJ] = true;
        int countOne = 1;
        int dist = 0;
        queue<pair<int, int>> q;
        q.emplace(startI, startJ);
        
        while (!q.empty()) {
            ++dist;
            int levelCount = q.size();
            // loop over one level in the queue
            for (int k = 0; k < levelCount; ++k) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                vector<pair<int, int>> pos{{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
                for (const auto& p : pos) {
                    int x = p.first;
                    int y = p.second;
                    if (x >=0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        visited[x][y] = true;
                        if (grid[x][y] == 0) {
                            q.emplace(x, y);
                            ++hit[x][y];
                            distSum[x][y] += dist;
                        } else if (grid[x][y] == 1) {
                            ++countOne;
                        }
                    }
                }
            }
        }
        
        return countOne == buildings;
        
    }
    
    
};
