class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9));
        vector<vector<bool>> cols(9, vector<bool>(9));
        vector<vector<bool>> squares(9, vector<bool>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '1';
                if (rows[i][num] || cols[num][j] || squares[3 * (i / 3) + j / 3][num])
                    return false;
                
                rows[i][num] = true;
                cols[num][j] = true;
                squares[3 * (i / 3) + j / 3][num] = true;
            }
        }
        return true;
    }
};
