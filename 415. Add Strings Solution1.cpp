class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1, t = 0;
        while (i >= 0 || j >= 0 || t) {
            if (i >= 0) t += num1[i--] - '0';
            if (j >= 0) t += num2[j--] - '0';
            res.push_back(t % 10 + '0');
            t /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
