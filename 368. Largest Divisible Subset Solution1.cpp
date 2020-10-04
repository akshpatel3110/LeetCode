class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), parent(n), res;
        if (n == 0) return res;
        int mx = 1, mx_idx = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > mx) {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        
        for (int i = 0, j = mx_idx; i < mx; ++i) {
            res.push_back(nums[j]);
            j = parent[j];
        }
        return res;
    }
};
