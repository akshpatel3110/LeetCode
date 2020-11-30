class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i = 0, j = 0; i < houses.size(); ++i) {
            // find the first heater which is >= to the current house
            while (j < heaters.size() && heaters[j] < houses[i])
                ++j;
            
            int dist; // the smaller distance of the left and right heaters
            if (j == 0) {
                dist = heaters[j] - houses[i];
            } else if (j < heaters.size()) {
                dist = min(houses[i] - heaters[j - 1], heaters[j] - houses[i]);
            } else {
                dist = houses[i] - heaters[j - 1];
            }
            res = max(res, dist);
        }
        return res;
    }
};
