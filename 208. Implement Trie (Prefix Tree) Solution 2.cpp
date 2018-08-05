class Trie {
public:
    /** Initialize your data structure here. */
    Trie() 
        : root(new TrieNode())
    {}
    
    ~Trie() {
        if (root)
            delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * node = root;
        for (const char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string & word) const {
        const TrieNode * node = find(word);
        return node && node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) const {
        return !!find(prefix); // equivalent to find(prefix) != nullptr
    }
    
private:
    struct TrieNode {
        TrieNode()
            : children(26, nullptr)
            , is_word(false)
        {}
        
        ~TrieNode() {
            for (auto child : children)
                if (child)
                    delete child;
        }
        
        vector<TrieNode*> children;
        bool is_word;
    };
    
    const TrieNode * find(const string & prefix) const {
        const TrieNode * node = root;
        for (const char c : prefix) {
            node = node->children[c - 'a'];
            if (!node)
                return nullptr;
        }
        return node;
    }
    
    TrieNode * root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
