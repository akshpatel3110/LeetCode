class Solution {
public:
    int i;
    string s;
    
    // Time: O(n)
    // Space: O(h)
    bool isValidSerialization(string _s) {
        i = 0;
        s = _s + ',';
        if (!dfs()) return false;
        return i == s.size(); // we might have unused chars in the end "9,#,#,1"
    }
    
    bool dfs() {
        if (i == s.size()) return false; // "1,#"
        if (s[i] == '#') {
            i += 2; // skip "#,"
            return true;
        }
        
        // skip "XXX,"
        while (s[i] != ',') ++i;
        ++i;
        
        // call left and right child
        return dfs() and dfs();
    }
};
