class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    bool increasingTriplet(vector<int>& nums) {
        vector<int> min_last(2, INT_MAX);
        for (auto x : nums) {
            // find the first number >= x
            int k = 0;
            while (k < min_last.size() && min_last[k] < x)
                ++k;
            
            if (k == 2) return true;
            min_last[k] = x;
        }
        return false;
    }
};
