class Solution {
public:
    // Time: O(nlogn)
    // Space: O(1)
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
            while (j < i && nums[i] - nums[j] > k) ++j;
            if (j < i && nums[i] - nums[j] == k) ++res;
        }
        return res;
    }
};
