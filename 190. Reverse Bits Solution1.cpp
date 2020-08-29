class Solution {
public:
    // Time: O(32) = O(1)
    // Space: O(n)
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) + (n >> i & 1);
        }
        return res;
    }
};
