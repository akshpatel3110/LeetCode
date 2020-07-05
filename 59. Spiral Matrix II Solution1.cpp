class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        int d = 0, x = 0, y = 0;
        for (int k = 1; k <= n * n; ++k) {
            res[x][y] = k;
            int i = x + dx[d], j = y + dy[d];
            if (i < 0 || i >= n || j < 0 || j >= n || res[i][j]) {
                d = (d + 1) % 4;
                i = x + dx[d];
                j = y + dy[d];
            }
            x = i;
            y = j;
        }
        return res;        
    }
};
