class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        for (int i = upper; ; --i) {
            auto t = to_string(i);
            auto num = stoll(t + string(t.rbegin(), t.rend()));
            for (long long j = upper; j * j >= num; --j)
                if (num % j == 0)
                    return num % 1337;
        }
        return 0;
    }
};
