class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, 
             vector<int16_t> & rows, vector<int16_t> & cols, vector<int16_t> & squares) {
        if (y == 9) {
            ++x;
            y = 0;
        }
        
        if (x == 9)
            return true;
        
        if (board[x][y] == '.') {
            for (int num = 1; num <= 9; ++num) {
                if (!(
                    (rows[x] & 1 << num) ||
                    (cols[y] & 1 << num) ||
                    (squares[3 * (x / 3) + (y / 3)] & 1 << num)
                    )
                   ) {
                    rows[x] |= 1 << num;
                    cols[y] |= 1 << num;
                    squares[3 * (x / 3) + (y / 3)] |= 1 << num;
                    board[x][y] = num + '0';
                    if (dfs(x, y + 1, board, rows, cols, squares))
                        return true;
                    
                    board[x][y] = '.';
                    rows[x] -= 1 << num;
                    cols[y] -= 1 << num;
                    squares[3 * (x / 3) + (y / 3)] -= 1 << num;
                }
            }
        } else {
            if (dfs(x, y + 1, board, rows, cols, squares))
                return true;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<int16_t> rows(9), cols(9), squares(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '0';
                rows[i] |= (1 << num);
                cols[j] |= (1 << num);
                squares[3 * (i / 3) + j / 3] |= (1 << num);
            }
        }
        dfs(0, 0, board, rows, cols, squares);
    }
};
