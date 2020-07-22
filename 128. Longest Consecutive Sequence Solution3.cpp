class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : nums) {
            if (!s.count(x))
                continue;
            
            s.erase(x);
            int l = x - 1, r = x + 1;
            while (s.count(l)) s.erase(l--);  
            while (s.count(r)) s.erase(r++);
            res = max(res, r - l - 1);
        }
        return res;
    }
};
