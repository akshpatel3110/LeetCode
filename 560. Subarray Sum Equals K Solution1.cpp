class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0, res = 0;
        hash[0] = 1;
        for (auto x : nums) {
            sum += x;
            res += hash[sum - k];
            ++hash[sum];
        }
        return res;
    }
};
