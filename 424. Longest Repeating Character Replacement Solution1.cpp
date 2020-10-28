class Solution {
public:
    // For each char, use two pointer
    // Time: O(26n)
    // Space: O(1)
    int characterReplacement(string s, int k) {
        int res = 0;
        for (char c = 'A'; c <= 'Z'; ++c) {
            // cnt is numbers of c
            for (int i = 0, j = 0, cnt = 0; i < s.size(); ++i) {
                if (s[i] == c) ++cnt;
                // delete s[j] from window is other chars appears more than k times
                while (i - j + 1 - cnt > k) {
                    if (s[j] == c) --cnt;
                    ++j;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
