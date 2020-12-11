class Solution {
public:
    int m, n;
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }
    
    void dfs(vector<vector<char>> & board, int x, int y) {
        if (board[x][y] != 'E') return;
        int cnt = 0;
        for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); ++i)
            for (int j = max(y - 1, 0); j <= min(y + 1, n - 1); ++j) {
                if (i == x && j == y) continue;
                if (board[i][j] == 'M' || board[i][j] == 'X')
                    ++cnt;
            }
        
        if (cnt) {
            board[x][y] = '0' + cnt;
            return;
        }
        
        board[x][y] = 'B';
        for (int i = max(x - 1, 0); i <= min(x + 1, m - 1); ++i)
            for (int j = max(y - 1, 0); j <= min(y + 1, n - 1); ++j) {
                if (i == x && j == y) continue;
                dfs(board, i, j);
            }
    }
};
