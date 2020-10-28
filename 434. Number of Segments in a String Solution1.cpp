class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int countSegments(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            while (i < n && s[i] != ' ') ++i;
            ++res;
        }
        return res;
    }
};
