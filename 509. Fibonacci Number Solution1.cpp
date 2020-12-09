class Solution {
public:
    // Time: O(N)
    // Space: O(1)
    int fib(int N) {
        if (N <= 1) return N;
        int a = 0, b = 1;
        for (int i = 2; i <= N; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
