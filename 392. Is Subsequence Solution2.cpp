
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cur_pos = -1;
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < t.size(); ++i)
            pos[t[i]].push_back(i);
        
        for (char c : s) {
            auto it = upper_bound(pos[c].begin(), pos[c].end(), cur_pos);
            if (it == pos[c].end())
                return false;
            cur_pos = *it;
        }
        return true;
    }
};
