class Solution {
public:
    // Time: O(n)
    // Space: O(log10(n))
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 1;
        while (i && s[i - 1] >= s[i]) --i;
        if (i == 0) return -1;
        int j = i;
        while (j + 1 < s.size() && s[j + 1] > s[i - 1]) ++j;
        swap(s[i - 1], s[j]);
        reverse(s.begin() + i, s.end());
        long long res = stoll(s);
        if (res > INT_MAX) return -1;
        return res;
    }
};
