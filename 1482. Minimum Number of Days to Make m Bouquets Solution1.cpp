class Solution {
public:
    bool check(vector<int> & bloomDay, int mid, int m, int k) {
        int count = 0;
        for (auto day : bloomDay) {
            if (day <= mid)
                ++count;
            else
                count = 0;
            
            if (count == k) {
                count = 0;
                --m;
                if (m == 0)
                    return true;
            }
        }
        return false;
    }
    
    // Time: O(nlog(maxDay - minDay))
    // Space: O(1)
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n / k < m)
            return -1;
        
        int l = INT_MAX, r = 0;
        for (auto day : bloomDay) {
            l = min(l, day);
            r = max(r, day);
        }
        
        while (l < r) {
            int mid = l + (long long)r >> 1;
            if (check(bloomDay, mid, m, k))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
