class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            res += max(0, prices[i + 1] - prices[i]);
        }
        return res;
    }
};
