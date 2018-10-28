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
*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval new_interval) {
        auto it = intervals.begin();
        while (it != intervals.end() && it->start < new_interval.start) 
            ++it;
        
        intervals.insert(it, new_interval);
        
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
