class Solution {
public:
    int gcd(int x, int y) {
        if (!y)
            return x;
        return gcd(y, x % y);
    }
    
    // Time: O(n ^ 2)
    // Space: O(n)
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int same_points = 0, same_verticals = 0;
            unordered_map<string, int> hash;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == points[j][0]) {
                    ++same_verticals;
                    if (points[i][1] == points[j][1])
                        ++same_points;
                } else {
                    int dx = x1 - x2, dy = y1 - y2, d = gcd(dy, dx);
                    string key = to_string(abs(dy / d)) + "/" + to_string(abs(dx / d));
                    if (dy / dx < 0)
                        key += '-';
                    
                    ++hash[key];
                }
            }
            // plus one for the point itself
            for (auto & [k, cnt] : hash)
                res = max(res, cnt + same_points + 1);
            
            res = max(res, same_verticals + 1);
        }
        return res;
    }
};
