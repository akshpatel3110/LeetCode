class Solution {
public:
    // Time: O(26n) == O(n)
    // Space: O(n)
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int u_cnt = 1; u_cnt <= 26; ++u_cnt) {
            unordered_map<char, int> hash;
            int unique = 0, satisfy = 0;
            for (int i = 0, j = 0; i < s.size(); ++i) {
                // add s[i]
                auto & vi = hash[s[i]];
                if (vi == 0) ++unique;
                ++vi;
                if (vi == k) ++satisfy;
                
                while (unique > u_cnt) {
                    // delete s[j]
                    auto & vj = hash[s[j]];
                    if (vj == k) --satisfy;
                    --vj;
                    if (vj == 0) --unique;
                    ++j;
                }
                
                // check and update, all unique chars satisfy
                if (unique == satisfy)
                    res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
