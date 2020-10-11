class Solution {
public:
    int u = 0;
    
    string decodeString(string s) {
        return dfs(s);
    }
    
    string dfs(const string & s) {
        string res;
        while (u < s.size() && s[u] != ']') {
            if (s[u] >= '0' && s[u] <= '9') {
                int i = u;
                while (s[i] >= '0' && s[i] <= '9') ++i;
                int cnt = stoi(s.substr(u, i - u));
                u = i + 1; // skip '['
                auto t = dfs(s);
                ++u; // skip ']'
                while (cnt--) res += t;
            } else {
                res += s[u++]; // chars
            }
        }
        return res;
    }
};
