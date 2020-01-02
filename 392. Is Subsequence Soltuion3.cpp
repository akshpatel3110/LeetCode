// Time: O(slogt)
// space: o(s)
// fix i, move j
// hash map: key char, value postions for that char
// vector pos[26][500000] -> O(s) time
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> pos;
        for (int k = 0; k < t.size(); ++k)
            pos[t[k]].push_back(k);
        
        int i = 0, j = -1;
        while (i < s.size()) {
            auto c = s[i];
            auto it = upper_bound(pos[c].begin(), pos[c].end(), j);
            if (it == pos[c].end())
                return false;
            j = *it;
            ++i;
        }
        return true;
    }
};
