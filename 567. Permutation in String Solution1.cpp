class Solution {
public:
    // sliding window: single pointer
    // Time: O(s1 + s2)
    // Space: O(s1)
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for (auto c : s1) ++m1[c];
        int cnt = 0, k = s1.size(); // k is window size
        for (int i = 0; i < s2.size(); ++i) {
            if (m1.count(s2[i])) {
                if (m2[s2[i]] < m1[s2[i]]) ++cnt; // matched one char
                ++m2[s2[i]];
            }
            
            if (i >= k) {
                if (m1.count(s2[i - k])) {
                    if (m2[s2[i - k]] <= m1[s2[i - k]]) --cnt; // lose one char
                    --m2[s2[i - k]];
                }
            }
            if (cnt == k) return true;
        }
        return false;
    }
};
