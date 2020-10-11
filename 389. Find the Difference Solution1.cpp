class Solution {
public:
    // Time: O(s + t)
    // Space: O(s)
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for (auto c : s) ++hash[c];
        for (auto c : t)
            if (--hash[c] < 0) return c;
        return -1;
    }
};
