class Solution {
public:
    vector<int> res;
    int n;
    
    // Time: O(n)
    // Space: O(log(10, n))
    vector<int> lexicalOrder(int n_) {
        n = n_;
        for (int i = 1; i <= 9; ++i)
            dfs(i);
        
        return res;
    }
    
    void dfs(int num) {
        if (num > n) return;
        res.push_back(num);
        for (int i = 0; i <= 9; ++i)
            dfs(num * 10 + i);
    }
};
