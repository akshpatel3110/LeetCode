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
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int new_diff = abs(sum - target);
                if (new_diff < diff) {
                    diff = new_diff;
                    res = sum;
                }
                if (sum < target)
                    ++j;
                else
                    --k;
            }
        }
        return res;
    }
};
