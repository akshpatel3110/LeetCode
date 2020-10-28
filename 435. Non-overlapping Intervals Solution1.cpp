class Solution {
public:
    // Time: O(nlogn)
    // Space: O1
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, prev = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < intervals[prev][1]) {
                ++res;
                
                // choose the interval with bigger end to minimize total number of intervals
                if (intervals[i][1] < intervals[prev][1])
                    prev = i;
            } else {
                prev = i;
            }
        }
        return res;
    }
};
