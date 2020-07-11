class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7, n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        vector<int> p(n);
        p[0] = 1;
        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] * 2 % mod;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0, j = n - 1; i <= j; ++i) {
            while (j >= i && nums[i] + nums[j] > target)
                --j;
            
            if (j >= i && nums[i] + nums[j] <= target)
                res = (res + p[j - i]) % mod;
        }
        return res;
    }
};
