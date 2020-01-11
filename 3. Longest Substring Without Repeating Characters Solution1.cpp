class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, i = 0, j = -1;
        unordered_map<char, int> m;
        while (i < s.size()) {
            if (m.count(s[i]) && m[s[i]] > j) {
                j = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - j);
            ++i;
        }
        return res;
    }
};
