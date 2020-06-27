class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        while (s.count(res))
            ++res;
        return res;
    }
};
