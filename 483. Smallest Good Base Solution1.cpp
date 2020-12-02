class Solution {
public:
    // two variable: k is the base, t is number of digit 1
    // n = 1 + k + k^2 + ... + k^(t - 1) = (k^t - 1) / (k - 1)
    //  minimizing k is equivalent to maximizing t
    // when k is 2, the largest t is log2(n + 1), which might not be an integer
    // when k is n - 1, the smallest t is 2, which must exist
    // The range of t is smaller, so we enumerate t instead of k, similar ideas seen in 
    // 857. Minimum Cost to Hire K Workers
    
    // Time: O(logn)
    // Space: O(1)
    string smallestGoodBase(string n) {
        using LL = long long;
        LL N = stoll(n);
        for (int t = log2(N + 1); t >= 3; --t) {
            LL k = pow(N, 1.0 / (t - 1));
            LL v = 0;
            for (int i = 0; i < t; ++i)
                v = v * k + 1;
            
            if (v == N)
                return to_string(k);
        }
        return to_string(N - 1);
    }
};
