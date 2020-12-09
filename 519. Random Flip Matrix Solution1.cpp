class Solution {
public:
    int r, c, tot;
    unordered_set<int> hash;
    
    Solution(int n_rows, int n_cols) 
        : r(n_rows)
        , c(n_cols)
        , tot(r * c)
    {}
    
    vector<int> flip() {
        while (true) {
            int x = rand() % (r * c);
            if (!hash.count(x)) {
                hash.insert(x);
                return {x / c, x % c};
            }
        }
    }
    
    void reset() {
        hash.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
