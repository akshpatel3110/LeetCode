class TreeAncestor {
    vector<vector<int>> f;
public:
    // Time: O(nlogn)
    // Space: O(nlogn)
    TreeAncestor(int n, vector<int>& parent) 
        : f(n, vector<int>(16, -1))
    {
        for (int i = 0; i < n; ++i)
            f[i][0] = parent[i];
            
        for (int j = 1; j < 16; ++j)
            for (int i = 0; i < n; ++i)
                if (f[i][j - 1] != -1)
                    f[i][j] = f[f[i][j - 1]][j - 1];
    }
    
    // Time: O(logn)
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 16; ++i) {
            if ((k >> i) & 1) {
                node = f[node][i];
            }
            if (node == -1)
                return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
