class Solution {
public:
    // Time: O(m + n)
    // Space: O(n)
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (auto c : magazine)
            ++hash[c];
        
        for (auto c : ransomNote) {
            if (hash[c] == 0) return false;
            else --hash[c];
        }
        return true;
    }
};
