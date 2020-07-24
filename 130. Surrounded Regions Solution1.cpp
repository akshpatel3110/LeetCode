class Solution {
public:
    int m, n;
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    
    // Time: O(mn)
    // Space: O(1)
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
        }
        
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board);
        }
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
    
    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '#';
        for (int d = 0; d < 4; ++d) {
            int i = x + dx[d], j = y + dy[d];
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
                dfs(i, j, board);
        }
    }
};
