/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/*
Insert interval into sorted position and call merge interval subroutine.
Binary search to find the first interval with interval.start >= new_interval.start (Loose Upper Bound)
Space: O(1) ignoring res vector and assuming vector insertion does not allocate new memory region.
Time: O(n)
*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval new_interval) {
        // find the first interval with start >= new_interval.start (Loose upper bound)
        int l = 0;
        int r = intervals.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid].start >= new_interval.start)
                r = mid;
            else
                l = mid + 1;
        }
        
        if (intervals.empty() || intervals[l].start < new_interval.start) {
            // there is no loose upper bound, insert new_interval to the end
            intervals.push_back(new_interval);
        } else {
            intervals.insert(intervals.begin() + l, new_interval);
        }
        
        // merge intervals
        vector<Interval> res;
        for (const auto & interval: intervals) {
            if (res.empty() || interval.start > res.back().end)
                res.push_back(interval);
            else
                res.back().end = max(res.back().end, interval.end);
        }
        return res;
    }
};
