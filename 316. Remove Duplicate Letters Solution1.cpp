class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> last;
        unordered_set<char> used;
        for (int i = 0; i < s.size(); ++i)
            last[s[i]] = i;
        
        for (int i = 0; i < s.size(); ++i) {
            if (used.count(s[i])) continue;
            while (res.size() && s[i] < res.back() && last[res.back()] > i) {
                used.erase(res.back());
                res.pop_back();
            }
            res += s[i];
            used.insert(s[i]);
        }
        return res;
    }
};
