class WordDictionary {
public:
    struct Node {
        vector<Node*> child;
        bool is_word;
        
        Node() 
            : child(26, nullptr)
            , is_word(false)
        {}
    };
    
    Node * root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    // Time: O(l)
    void addWord(string word) {
        auto p = root;
        for (auto c : word) {
            int i = c - 'a';
            if (!p->child[i])
                p->child[i] = new Node();
            p = p->child[i];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    // Time: O(nl), worst case sarch all nodes in the trie
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
    bool dfs(Node * p, const string & word, int u) {
        if (u == word.size())
            return p->is_word;
        
        if (word[u] != '.') {
            int i = word[u] - 'a';
            if (!p->child[i])
                return false;
            
            return dfs(p->child[i], word, u + 1);
        } else {
            // try all possible chars
            for (int i = 0; i < 26; ++i) {
                if (p->child[i] && dfs(p->child[i], word, u + 1))
                    return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
