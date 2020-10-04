class Solution {
public:
    // Time: O(32) = O(1)
    // Space: O(32) = O(1)
    int getSum(int a, int b) {
        if (!a) return b;
        int sum = a ^ b, carry = (unsigned)(a & b) << 1;
        return getSum(carry, sum);
    }
};
