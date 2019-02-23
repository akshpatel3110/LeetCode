// Brute force
// Time O(n^3)
// Space O(1)

class Solution {
public:
    bool array_contains(vector<int>& nums, int num) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == num)
                return true;
        }
        return false;
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int cur_num = num;
            int cur_streak = 1;
            
            while (array_contains(nums, cur_num + 1)) {
                ++cur_num;
                ++cur_streak;
            }
            res = max(res, cur_streak);
        }
        return res;
    }
};
