class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int p = abs(nums[i]) - 1;
            nums[p] *= -1;
            if (nums[p] > 0)
                res.push_back(p + 1);
        }
        return res;
    }
};
