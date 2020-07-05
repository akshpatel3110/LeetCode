class Solution {
public:
    // Time: O(m + n)
    // Space: O(1)
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, t = 0;
        while (i >= 0 || j >= 0 || t == 1) {
            t += i >= 0 ? a[i--] - '0' : 0;
            t += j >= 0 ? b[j--] - '0' : 0;
            res += to_string(t % 2);
            t /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
