class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto x : nums)
            if (x)
                nums[i++] = x;
        
        while (i < nums.size())
            nums[i++] = 0;
    }
};
