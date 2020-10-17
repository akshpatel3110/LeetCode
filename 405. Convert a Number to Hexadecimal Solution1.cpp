class Solution {
public:
    // Time: O(1)
    // Space: O(1)
    string toHex(unsigned int num) {
        if (!num) return "0";
        string res, nums = "0123456789abcdef";
        while (num) {
            res += nums[num & 0xf];
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
