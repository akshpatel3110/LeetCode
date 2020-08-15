uclass Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int f = nums[0], g = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int fn = f * nums[i], gn = g * nums[i];
            f = max({nums[i], fn, gn});
            g = min({nums[i], fn, gn});
            res = max(res, f);
        }
        return res;
    }
};
