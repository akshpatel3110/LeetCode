class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (!k) {
            for (int i = 1; i < nums.size(); ++i)
                if (!nums[i - 1] && !nums[i])
                    return true;
            return false;
        }
        
        int n = nums.size();
        vector<int> s(n + 1);
        unordered_set<int> hash;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
            if (i >= 2 && hash.count(s[i] % k)) return true;
            hash.insert(s[i - 1] % k); // the next number at i + 1 only use i - 1
        }
        return false;
    }
};
