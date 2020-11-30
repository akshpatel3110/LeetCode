class Solution {
public:
    // Time: O(31n)
    // Space: O(1)
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i <= 30; ++i) {
            int ones = 0;
            for (int num : nums) {
                if (num >> i & 1)
                    ++ones;
            }
            res += ones * (n - ones);
        }
        return res;
    }
};
