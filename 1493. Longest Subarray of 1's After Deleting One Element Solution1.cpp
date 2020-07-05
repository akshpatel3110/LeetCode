class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                ++cnt;
            
            while (cnt > 1)
                cnt -= !nums[j++];
            
            res = max(res, i - j);
        }
        return res;
    }
};
