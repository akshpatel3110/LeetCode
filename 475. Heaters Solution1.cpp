class Solution {
public:
    bool check(int mid, vector<int>& houses, vector<int>& heaters) {
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            while (j < heaters.size() && abs(houses[i] - heaters[j]) > mid)
                ++j;
            
            if (j == heaters.size())
                return false;
        }
        return true;
    }
    
    // Time: O(mlogm + nlogn + (m + n)(logd)) where d is max(houses.back(), heaters.back())
    // Space: O(1)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = max(houses.back(), heaters.back());
        while (l < r) {
            int mid = l + (long long)r >> 1;
            if (check(mid, houses, heaters))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
