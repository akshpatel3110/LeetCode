class Solution {
public:
    vector<int> p;
    
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    // Union find
    // Time: O(n ^ 2)
    // Space: O(n)
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        p.resize(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        
        int res = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] && find(i) != find(j)) {
                    p[find(i)] = find(j);
                    --res;
                }
            }
        }
        return res;            
    }
};
