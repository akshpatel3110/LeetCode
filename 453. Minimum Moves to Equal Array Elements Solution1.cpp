class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int minMoves(vector<int>& nums) {
        int minv = INT_MAX;
        for (auto x : nums)
            minv = min(minv, x);
        
        int res = 0;
        for (auto x : nums)
            res += x - minv;
        return res;
    }
};
