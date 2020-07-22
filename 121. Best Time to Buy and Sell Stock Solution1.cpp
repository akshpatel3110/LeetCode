class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int maxProfit(vector<int>& prices) {
        int res = 0, minp = INT_MAX;
        for (auto price : prices) {
            res = max(res, price - minp);
            minp = min(price, minp);
        }
        return res;
    }
};
