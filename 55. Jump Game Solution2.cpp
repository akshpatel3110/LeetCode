class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> f(nums.size() + 1);
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (i > f[i] || f[i] >= n - 1) 
                break;
            f[i + 1] = max(f[i], i + nums[i]);
            ++i;
        }
        return f[i] >= n - 1;
    }
};
