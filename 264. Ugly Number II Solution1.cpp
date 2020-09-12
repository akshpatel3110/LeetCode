class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int nthUglyNumber(int n) {
        vector<int> nums{1};
        int i = 0, j = 0, k = 0;
        while (nums.size() < n) {
            int t = min({nums[i] * 2, nums[j] * 3, nums[k] * 5});
            nums.push_back(t);
            if (nums[i] * 2 == t) ++i;
            if (nums[j] * 3 == t) ++j;
            if (nums[k] * 5 == t) ++k;
        }
        return nums.back();
    }
};
