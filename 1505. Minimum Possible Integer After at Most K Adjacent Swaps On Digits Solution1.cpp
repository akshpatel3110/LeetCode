class Solution {
public:
    vector<int> tree; // starts from 1
    int n;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i))
            tree[i] += v;
    }
    
    int get_sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tree[i];
        return res;
    }
    
    // Time: O(nlogn)
    // Space: O(n)
    string minInteger(string num, int k) {
        n = num.size();
        vector<queue<int>> q(10);
        
        // record the positions of each number
        for (int i = 0; i < n; ++i)
            q[num[i] - '0'].push(i);
            
        tree.resize(n + 1);
        string res;
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d < 10; ++d) {
                if (q[d].empty())
                    continue;
                
                int x = q[d].front(); // original position
                int pos = x + get_sum(x + 1); // current position
                if (pos - i <= k) {
                    k -= pos - i;
                    res += to_string(d);
                    q[d].pop();
                    add(1, 1);
                    add(x + 1, -1);
                    break;
                }
            }
        }
        return res;
    }
};
