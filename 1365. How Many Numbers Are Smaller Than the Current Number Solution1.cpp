class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            for (int x : nums) {
                if (x < nums[i])
                    ++res[i];
            }
        }
        return res;
    }
};
