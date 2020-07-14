class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (auto x : left) {
            res = max(res, x);
        }
        
        for (auto x : right) {
            res = max(res, n - x);
        }
        return res;
    }
};
