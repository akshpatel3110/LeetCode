// Time: O(o(s) + o(t))
// Space: O(1)
// fix i, move j
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j < t.size() && s[i] != t[j])
                ++j;
            
            if (j == t.size())
                return false;
            ++i;
            ++j;
        }
        return true;
    }
};
