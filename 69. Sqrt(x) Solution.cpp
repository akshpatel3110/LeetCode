class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int m = l + (long long) r + 1 >> 1;
            if (m <= x / m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
