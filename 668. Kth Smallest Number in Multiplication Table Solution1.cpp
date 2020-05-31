class Solution {
public:
    // Time: O(mlog(mn))
    // Space: O(1)
    int numbers_less_than_or_equal(int mid, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i)
            count += min(n, mid / i);
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + (long long)r >> 1;
            if (numbers_less_than_or_equal(mid, m, n) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
