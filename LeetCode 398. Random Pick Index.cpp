class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums_)
        : nums(std::move(nums_))
    {}
    
    int pick(int target) {
        int count = 0;
        int res;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++count;
                
                // can be combined into rand() % count == 0
                if (count == 1 || rand() % count == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
