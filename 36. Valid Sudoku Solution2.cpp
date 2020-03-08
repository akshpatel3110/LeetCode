class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') 
                    continue;
                
                string t = "*" + to_string(board[i][j]);
                string row = to_string(i) + t, col = t + to_string(j), square = to_string(i / 3) + t + to_string(j / 3);
                if (st.count(row) || st.count(col) || st.count(square)) 
                    return false;
                
                st.insert(row);
                st.insert(col);
                st.insert(square);
            }
        }
        return true;
    }
};
