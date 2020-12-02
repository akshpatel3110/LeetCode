class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            int j = i + 1;
            while (j < nums.size() && nums[j] == 1) ++j;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
