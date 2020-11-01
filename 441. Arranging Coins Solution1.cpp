class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    int arrangeCoins(int n) {
        int l = 0, r = n;
        while (l < r) {
            long long m = l + (long long)r + 1 >> 1;
            if (m * (m + 1) / 2 <= n)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
