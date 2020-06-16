class Solution {
public:
    // Time: O(n)
    // Space: O(1 << k)
    bool hasAllCodes(string s, int k) {
        unordered_set<int> hset;
        for (int i = 0, w = 0; i < s.size(); ++i) {
            w = w * 2 + s[i] - '0';
            if (i >= k)
                w -= s[i - k] - '0' << k;
            
            if (i >= k - 1)
                hset.insert(w);
        }
        return hset.size() == (1 << k);
    }
};
