class Solution {
public:
    int get(int prefix, int n) {
        auto X = to_string(n), Y = to_string(prefix);
        long long p = 1;
        int res = 0, diff = X.size() - Y.size();
        for (int i = 0; i < diff; ++i) {
            res += p;
            p *= 10;
        }
        X = X.substr(0, Y.size());
        if (X == Y)
            res += n - prefix * p + 1;
        else if (X > Y)
            res += p;
        return res;
    }
    
    // Time: O(logn * logn)
    // Space: O(1)
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            int cnt = get(prefix, n);
            if (k > cnt) {
                k -= cnt;
                ++prefix;
            } else {
                --k;
                prefix *= 10;
            }
        }
        return prefix;
    }
};
