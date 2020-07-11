class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        deque<int> q;
        int res = INT_MIN;

        for (int j = 0; j < n; ++j) {
            int xj = points[j][0], yj = points[j][1];

            while (q.size() && xj - points[q.front()][0] > k)
                q.pop_front();

            if (q.size()) {
                int i = q.front();
                res = max(res, points[i][1] - points[i][0] + yj + xj);
            }

            while (q.size() && yj - xj >= points[q.back()][1] - points[q.back()][0])
                q.pop_back();

            q.push_back(j);
        }

        return res; 
    }
};
