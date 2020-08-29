class Solution {
public:
    struct Node {
        int id = -1;
        Node * child[26] = {nullptr};
    };
    
    Node * root;
    int m;
    int n;
    unordered_set<int> ids;
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    
    // The reasons we use trie
    // 1. For each char, it is O(1) hash look up to make the decision, otherwise we have to traverse the vector of words
    // 2. During traversal, we can instantly know whether the current path is a word by checking the id field
    
    // Time: O((n ^ 2) * (3 ^ l) * l)
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        m = b.size();
        if (m == 0) return {};
        n = b[0].size();
        
        root = new Node();
        
        // insert words into trie
        for (int i = 0; i < words.size(); ++i) {
            auto p = root;
            for (auto c : words[i]) {
                int u = c - 'a';
                if (!p->child[u])
                    p->child[u] = new Node();
                p = p->child[u];
            }
            p->id = i;
        }
        
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                int u = b[x][y] - 'a';
                if (root->child[u])
                    dfs(x, y, root->child[u], b);
            }
        }
        
        vector<string> res;
        for (auto id : ids)
            res.push_back(words[id]);
        return res;
    }
    
    void dfs(int x, int y, Node * p, vector<vector<char>>& b) {
        if (p->id != -1)
            ids.insert(p->id);
        
        char c = b[x][y];
        b[x][y] = '.';
        for (int d = 0; d < 4; ++d) {
            int i = x + dx[d], j = y + dy[d];
            if (i >= 0 && i < m && j >= 0 && j < n && b[i][j] != '.') {
                int u = b[i][j] - 'a';
                if (p->child[u])
                    dfs(i, j, p->child[u], b);
            }
        }
        b[x][y] = c;
    }
};
