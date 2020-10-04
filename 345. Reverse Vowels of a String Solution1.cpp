class Solution {
public:
    string s = "aeiou";
    
    bool is_vowel(char c) {
        return s.find(tolower(c)) != -1;
    }
    
    // Time: O(n)
    // Space: O(1)
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (i < j && !is_vowel(s[i])) ++i;
            while (i < j && !is_vowel(s[j])) --j;
            swap(s[i], s[j]);
        }
        return s;
    }
};
