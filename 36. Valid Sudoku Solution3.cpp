class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int16_t> rows(9), cols(9), squares(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '1';
                if ((rows[i] & (1 << num)) ||
                    (cols[j] & (1 << num)) ||
                    (squares[3 * (i / 3) + (j / 3)] & (1 << num)))
                    return false;
                
                rows[i] |= (1 << num);
                cols[j] |= (1 << num);
                squares[3 * (i / 3) + (j / 3)] |= (1 << num);
            }
        }
        return true;
    }
};
