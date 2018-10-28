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
We can also construct the first overlapping interval and push it to result vector and dynamically change its end value instead of pushing it after the overlapping phase exits.
Space: O(1) ignoring res vector
Time: O(n)
8ms beats 99.30%
*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval new_interval) {
        vector<Interval> res;
        bool overlapping_interval_pushed = false;
        int overlap_start = new_interval.start;
        int overlap_end = new_interval.end;

        for (const auto & interval : intervals) {
            if (interval.end < new_interval.start) {
                res.push_back(interval);
            } else if (interval.start <= new_interval.end) {
                overlap_start = min(overlap_start, interval.start);
                overlap_end = max(overlap_end, interval.end);
            } else {
                if (!overlapping_interval_pushed) {
                    res.emplace_back(overlap_start, overlap_end);
                    overlapping_interval_pushed = true;
                }
                res.push_back(interval);
            }
        }
        
        if (!overlapping_interval_pushed) {
            res.emplace_back(overlap_start, overlap_end);
        }
        
        return res;
    }
};
