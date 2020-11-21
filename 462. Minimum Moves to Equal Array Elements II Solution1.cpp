class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        int res = 0;
        for (int x : nums)
            res += abs(x - mid);
        return res;
    }
};
