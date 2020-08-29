class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    // The key is finding the longest palindrome prefix, which can be achieved by KMP.
    string shortestPalindrome(string s) {
        int n = s.size();
        string t(s.rbegin(), s.rend());
        string str = ' ' + s + '#' + t;
        vector<int> ne(2 * n + 2);
        for (int i = 2, j = 0; i < 2 * n + 2; ++i) {
            while (j && str[i] != str[j + 1])
                j = ne[j];
            
            if (str[i] == str[j + 1])
                ++j;
            
            ne[i] = j;
        }
        int len = ne.back();
        string l = s.substr(0, len), r = s.substr(len);
        return string(r.rbegin(), r.rend()) + l + r;
    }
};
