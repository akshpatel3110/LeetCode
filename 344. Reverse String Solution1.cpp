class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};
