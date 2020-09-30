class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int minPatches(vector<int>& nums, int n) {
        long long v = 1;
        int res = 0, i = 0;
        while (v <= n) {
            if (i < nums.size() && nums[i] <= v) {
                v += nums[i++];
            } else {
                v += v;
                ++res;
            }
        }
        return res;
    }
};
