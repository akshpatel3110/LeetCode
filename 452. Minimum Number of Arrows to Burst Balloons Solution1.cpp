class Solution {
public:
    // greedy
    // Time: O(nlogn)
    // Space: O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1, e = points[0][1];
        for (auto & p : points) {
            if (p[0] <= e) {
                e = min(e, p[1]);
            } else {
                // interval disjoint, need another arrow
                ++res;
                e = p[1];
            }
        }
        return res;
    }
};
