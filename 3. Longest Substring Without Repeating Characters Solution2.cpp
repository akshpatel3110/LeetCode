class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, i = 0, j = -1;
        vector<int> m(128, -1);
        while (i < s.size()) {
            j = max(j, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - j);
            ++i;
        }
        return res;
    }
};
