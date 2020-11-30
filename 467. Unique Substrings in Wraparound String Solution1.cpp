class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> hash;
        for (int i = 0; i < p.size();) {
            int j = i + 1;
            while (j < p.size() && (p[j] == p[j - 1] + 1 || p[j] == 'a' && p[j - 1] == 'z'))
                ++j;
            
            while (i < j) {
                hash[p[i]] = max(hash[p[i]], j - i);
                ++i;
            }
        }
        int res = 0;
        for (auto [k, v] : hash)
            res += v;
        return res;
    }
};
