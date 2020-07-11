class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (i < 2 || nums[i] > nums[j - 2]) { // be careful here, not nums[i - 2]
                nums[j] = nums[i];
                ++j;
            }
            ++i;
        }
        return j;
    }
};
