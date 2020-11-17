class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) ++hash[c];
        sort(s.begin(), s.end(), [&](char l, char r) {
            if (hash[l] != hash[r]) return hash[l] > hash[r];
            return l < r;
        });
        return s;
    }
};
