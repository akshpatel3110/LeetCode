class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l + 1 < nums.size() && nums[l + 1] >= nums[l]) ++l;
        if (l == r) return 0;
        while (r - 1 >= 0 && nums[r - 1] <= nums[r]) --r;
        int r_min = *min_element(nums.begin() + l + 1, nums.end());
        while (l >= 0 && nums[l] > r_min) --l;
        int l_max = *max_element(nums.begin(), nums.begin() + r);
        while (r < nums.size() && nums[r] < l_max) ++r;
        return r - l - 1;
    }
};
