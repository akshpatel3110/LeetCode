class Solution {
public:
    // Time: O(n)
    // Space: O(s + t)
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (auto c : t)
            ++mt[c];
        
        int min_left, min_len = INT_MAX;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            ++ms[s[i]];
            if (ms[s[i]] <= mt[s[i]]) ++cnt;
            while (ms[s[j]] > mt[s[j]]) {
                --ms[s[j]];
                ++j;
            }
            if (cnt == t.size() && i - j + 1 < min_len) {
                min_left = j;
                min_len = i - j + 1;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};
