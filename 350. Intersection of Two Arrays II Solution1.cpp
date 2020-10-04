class Solution {
public:
    // Time: O(m + n)
    // Space: O(m)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (auto x : nums1) 
            ++hash[x];
        
        for (auto x : nums2) {
            if (--hash[x] >= 0) 
                res.push_back(x);
        }
        return res;
    }
};
