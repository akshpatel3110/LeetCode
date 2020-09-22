class NumMatrix {
public:
    vector<vector<int>> f;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        f = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
    }
    
    // Time: O(1)
    // Space: O(n ^ 2)
    int sumRegion(int x1, int y1, int x2, int y2) {
        ++x1, ++x2, ++y1, ++y2;
        return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
