class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int lengthOfLastWord(string s) {
        int r = s.size() - 1, res = 0;
        while (r >= 0 && s[r] == ' ')
            --r;
        
        while (r >= 0 && s[r] != ' ') {
            --r;
            ++res;
        }
        return res;
    }
};
