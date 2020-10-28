class Solution {
public:
    struct Node {
        int child[2];
    };
    
    vector<Node> tr; 
    
    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (!tr[p].child[v])  {
                tr.push_back(Node({0, 0}));
                tr[p].child[v] = tr.size() - 1;
            }
            p = tr[p].child[v];
        }
    }
    
    int query(int x) {
        int p = 0, res = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (tr[p].child[!v]) {
                res += 1 << i;
                p = tr[p].child[!v];
            } else {
                p = tr[p].child[v];
            }
        }
        return res;
    }
    
    // Time: O(n)
    // Space: O(n)
    int findMaximumXOR(vector<int>& nums) {
        tr.push_back(Node({0, 0}));
        int res = 0;
        for (auto x : nums) {
            res = max(res, query(x));
            insert(x);
        }
        return res;
    }
};
