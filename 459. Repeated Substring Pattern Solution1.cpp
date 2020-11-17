class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int len = n / 2; len >= 1; --len) {
            if (n % len == 0) {
                int cnt = n / len;
                bool match = true;
                for (int i = 0; i < cnt; ++i) {
                    for (int j = 0; j < len; ++j) {
                        if (s[i * len + j] != s[j]) {
                            match = false;
                            break;
                        }
                    }
                    if (!match) break;
                }
                if (match) return true;
            }
        }
        return false;        
    }
};
