class Solution {
public:
    int r, c, tot;
    unordered_map<int, int> hash;
    
    Solution(int n_rows, int n_cols) 
        : r(n_rows)
        , c(n_cols)
        , tot(r * c)
    {}
    
    vector<int> flip() {
        int x = rand() % tot;
        int v = hash.count(x) ? hash[x] : x;
        // delete v <==> set it to the end and deletion of end in hash if present
        if (hash.count(tot - 1)) {
            hash[x] = hash[tot - 1];
            hash.erase(tot - 1);
        } else {
            hash[x] = tot - 1;
        }
        --tot;
        return {v / c, v % c};
    }
    
    void reset() {
        tot = r * c;
        hash.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
