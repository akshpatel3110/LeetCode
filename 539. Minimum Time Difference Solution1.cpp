class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 24 * 60) return 0;
        int res = INT_MAX;
        vector<int> p;
        for (auto & t : timePoints) {
            int h, m;
            sscanf(t.c_str(), "%d:%d", &h, &m);
            p.push_back(h * 60 + m);
        }
        sort(p.begin(), p.end());
        for (int i = 1; i < n; ++i)
            res = min(res, p[i] - p[i - 1]);
        
        res = min(res, 24 * 60 - p.back() + p[0]);
        return res;
    }
};
