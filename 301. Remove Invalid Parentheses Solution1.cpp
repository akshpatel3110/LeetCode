class Solution {
public:
    vector<string> res;
    
    // l is the minimum number of '(' to delete
    // l is the minimum number of ')' to delete
    // diff is number of '(' - number of ')'
    // Time: O(2 ^ n * n): each paren has the choice of being kept or removed
    // SpaceL O(n)
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto c : s) {
            if (c == '(') {
                ++l;
            } else if (c == ')') {
                if (l == 0) ++r;
                else --l;
            }
        }
        dfs(s, 0, "", l, r, 0);
        return res;
    }
    
    void dfs(const string & s, int u, string path, int l, int r, int diff) {
        if (u == s.size()) {
            if (!diff) // l and r must be 0 here
                res.push_back(move(path));
            return;
        }
        
        if (s[u] != '(' && s[u] != ')') {
            while (u < s.size() && s[u] != '(' && s[u] != ')') {
                path += s[u];
                ++u;
            }
            
            dfs(s, u, path, l, r, diff);
        } else if (s[u] == '(') {
            int i = u;
            while (i < s.size() && s[i] == '(') ++i;
            l -= i - u;
            for (int j = i - u; j >= 0; --j) {
                if (l >= 0) dfs(s, i, path, l, r, diff);
                path += '(';
                ++diff;
                ++l;
            }
        } else {
            int i = u;
            while (i < s.size() && s[i] == ')') ++i;
            r -= i - u;
            for (int j = i - u; j >= 0; --j) {
                if (diff >= 0 && r >= 0) dfs(s, i, path, l, r, diff);
                path += ')';
                --diff;
                ++r;
            }            
        }
        
    }
};
