class Solution {
public:
    // Time: O(log7(num))
    // Space: O(1)
    string convertToBase7(int num) {
        if (!num) return "0";
        bool is_neg = num < 0;
        num = abs(num);
        string res;
        while (num) {
            res += to_string(num % 7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if (is_neg) res = "-" + res;
        return res;
    }
};
