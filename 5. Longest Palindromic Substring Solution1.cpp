class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (n - i <= len / 2)
                break;
            spread(s, i, i, n, start, len);
            spread(s, i, i + 1, n, start, len);
        }
        return s.substr(start, len);
    }
    
    void spread(const string& s, int l, int r, int n, int & start, int & len) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
        }
        
        if (r - l - 1 > len) {
            start = l + 1;
            len = r - l - 1;
        }
    }
};
