class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};
