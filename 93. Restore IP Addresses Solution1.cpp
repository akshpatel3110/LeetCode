class Solution {
public:
    // Time: O(C_(n - 1)_3) or C_11_3: we choose 3 dots from n - 1 positions
    // Space: O(4) = O(1): path is moved, the recursion depth is at most 4
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
    
    // u: position for s
    // k: the kth integer (separated by dot)
    void dfs(const string & s, int u, int k, string path) {
        if (u == s.size()) {
            if (k == 4) {
                path.pop_back();
                res.push_back(move(path));
            }
            return;
        }
        if (k == 4)
            return;
        
        for (int i = u, v = 0; i < s.size(); ++i) {
            // leading zeros
            if (i > u && s[u] == '0')
                return;
            
            v = v * 10 + s[i] - '0';
            if (v <= 255)
                dfs(s, i + 1, k + 1, path + to_string(v) + '.');
            else
                return;
        }
    }
};
