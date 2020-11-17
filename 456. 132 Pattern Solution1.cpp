class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int two = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < two) return true;
            while (stk.size() && nums[i] > stk.top()) {
                two = max(two, stk.top());
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
