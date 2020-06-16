class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1, k = n - 1; j < k; ++j) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target)
                    --k;
                
                int sum = nums[i] + nums[j] + nums[k];
                int new_diff = abs(sum - target);
                if (diff > new_diff) {
                    diff = new_diff;
                    res = sum;
                }
                
                if (k - 1 > j) {
                    sum = nums[i] + nums[j] + nums[k - 1];
                    new_diff = target - sum;
                    if (diff > new_diff) {
                        diff = new_diff;
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
