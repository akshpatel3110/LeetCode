class Solution {
public:
    // Time: O(nlogn)
    // Space: O(1)
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end(), greater<int>());
        for (int h = c.size(); h; --h) {
            if (c[h - 1] >= h)
                return h;
        }
        return 0;
    }
};
