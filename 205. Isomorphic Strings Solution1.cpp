class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st, ts;
        for (int i = 0; i < s.size(); ++i) {
            if (st.count(s[i])) {
                if (st[s[i]] != t[i])
                    return false;
            } else {
                st[s[i]] = t[i];
            }
            
            if (ts.count(t[i])) {
                if (ts[t[i]] != s[i])
                    return false;
            } else {
                ts[t[i]] = s[i];
            }
        }
        return true;
    }
};
