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
The heap stores all overlapping events. The heap's head is the event that has earliest end/finish time. 

When a new event comes, we greedily choose the event X that finished the earliest. If the new event does not overlap with X, then the new event can re-use X's room, or simply extend X's event to the new event's end time.

If the new event overlaps with X, then it must overlaps with all other events in the heap. So a new room must be created.

The reason for correctness is the invariant: heap size is always the minimum number of rooms we need so far.
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), [] (const Interval& l, const Interval& r) { return l.start < r.start; });

        priority_queue<int, vector<int>, greater<int>> q;

        q.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= q.top())
                q.pop();

            q.push(intervals[i].end);
        }
        
        return q.size();        
    }

};
