uclass Solution {
public:
    // Time: O((n ^ 2) * (3 ^ k))
    // Space: O(k) where k is sizeof(word)
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) 
            return false;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, 0, i, j)) 
                    return true;
            }
        }
        return false;
    }
    
    vector<int> di{0, 1, 0, -1}, dj{1, 0, -1, 0};
    
    bool dfs(vector<vector<char>> & board, const string & word, 
             int u, int i, int j) {
        if (board[i][j] != word[u]) 
            return false;
        
        if (u == word.size() - 1)
            return true;
        
        char c = board[i][j];
        board[i][j] = '.';
        for (int d = 0; d < 4; ++d) {
            int x = i + di[d], y = j + dj[d];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '.')
                continue;
            
            if (dfs(board, word, u + 1, x, y))
                return true;
        }
        board[i][j] = c;
        return false;
    }
};
