class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + r + 1 >> 1;
            // mth largest number's index is n - m
            if (c[n - m] >= m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
