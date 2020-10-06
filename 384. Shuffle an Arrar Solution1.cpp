class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int>& nums_)
        : nums(nums_)
    {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto res = nums;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            swap(res[i], res[i + rand() % (n - i)]);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
