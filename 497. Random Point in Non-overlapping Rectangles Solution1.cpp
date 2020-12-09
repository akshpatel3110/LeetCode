class Solution {
public:
    vector<vector<int>> rects;
    int n;
    vector<int> s;
    
    Solution(vector<vector<int>>& _rects) {
        rects = _rects;
        n = rects.size();
        s.push_back(0);
        for (auto & r : rects) {
            int dx = r[2] - r[0] + 1;
            int dy = r[3] - r[1] + 1;
            s.push_back(s.back() + dx * dy);
        }
    }
    
    vector<int> pick() {
        int p = rand() % s.back() + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= p) r = mid;
            else l = mid + 1;
        }
        auto & t = rects[l - 1];
        int dx = t[2] - t[0] + 1;
        int dy = t[3] - t[1] + 1;
        return {rand() % dx + t[0], rand() % dy + t[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
