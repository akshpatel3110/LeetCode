class Solution {
public:
    using LL = long long;
    const int mod = 1e9 + 7;
    vector<LL> s, ss;
    int n;
    
    int count_le(LL m) {
        int count = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            while (s[i] - s[j] > m)
                ++j;
            if (i > j)
                count += i - j;
        }
        return count;
    }
    
    LL sum_le(LL m) {
        LL sum = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            while (s[i] - s[j] > m)
                ++j;
            if (i > j) {
                sum += s[i] * (i - j) - ss[i - 1];
                if (j)
                    sum += ss[j - 1];
            }
        }
        return sum; 
    }
    
    LL sorted_ss(int k) {
        LL l = 0, r = ss.back();
        while (l < r) {
            LL m = l + r >> 1;
            if (count_le(m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return sum_le(l) - (count_le(l) - k) * l;
    }
    
    // Time: O(nlogd) where d is the sum of the whole array
    // Space: O(n)
    int rangeSum(vector<int>& nums, int _n, int left, int right) {
        n = _n;
        s.resize(n + 1), ss.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
            ss[i] = ss[i - 1] + s[i];
        }
        return (sorted_ss(right) - sorted_ss(left - 1)) % mod;
    }
};
