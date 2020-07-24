class Solution {
public:
    // Time: O(n ^ 2 * logn)
    // Space: O(n)
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        
        sort(sums.begin(), sums.end());
        long long res = 0;
        for (int i = left - 1; i <= right - 1; ++i) {
            res += sums[i];
        }
        return res % mod;
    }
};
