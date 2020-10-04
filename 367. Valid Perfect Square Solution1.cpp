class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int m = l + (long long)r + 1 >> 1;
            if (m <= num / m)
                l = m;
            else
                r = m - 1;
        }
        return r * r == num;
    }
};
