class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    double myPow(double x, int n) {
        using LL = long long;
        double res = 1;
        bool minus = n < 0;
        for (LL t = abs(LL(n)); t; t >>= 1) {
            if (t & 1)
                res *= x;
            x *= x;
        }
        if (minus)
            res = 1 / res;
        return res;
    }
};
