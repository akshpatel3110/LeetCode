class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    // sliding window
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hash;
        for (auto c : p) ++hash[c];
        int unique = hash.size();
        vector<int> res;
        for (int i = 0, j = 0, satisfy = 0; i < s.size(); ++i) {
            if (--hash[s[i]] == 0) ++satisfy;
            if (i - j + 1 > p.size()) { // use if instead of while since j can only move by at most 1 step
                if (hash[s[j]] == 0) --satisfy;
                ++hash[s[j]];
                ++j;
            }
            if (satisfy == unique) res.push_back(j);
        }
        return res;
    }
};
