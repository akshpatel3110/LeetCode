class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        long long num = start + (n + len - 1) / len - 1;
        int digit_idx =  (n % len ? n % len : len) - 1;
        return to_string(num)[digit_idx] - '0';
    }
};
