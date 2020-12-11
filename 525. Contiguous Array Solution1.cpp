class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        hash[0] = 0;
        int res = 0, ones = 0, zeros = 0;
        for (int i = 1; i <= nums.size(); ++i) { // prefix sum index starts from 1
            if (nums[i - 1] == 0) ++zeros;
            else ++ones;
            int v = ones - zeros;
            if (hash.count(v)) res = max(res, i - hash[v]);
            else hash[v] = i;
        }
        return res;
    }
};
