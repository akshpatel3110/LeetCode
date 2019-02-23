// Time O(nlgn) + O(n) = o(nlgn)
// Space O(1) sort array in place

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int res = 1;
        int cur_streak = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    ++cur_streak;
                } else {
                    // previous streak ends
                    res = max(res, cur_streak);
                    cur_streak = 1;
                }
            } // skip equal
        }
        
        // input [100, 4, 200, 1, 3, 2], cur_streak is 4, res is 1
        return max(res, cur_streak);
    }
};
