class Solution {
public:
    // Time: O(m + n)
    // Space: O(m)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto x: nums2)
            if (hash.count(x)) {
                res.push_back(x);
                hash.erase(x);
            }
        return res;        
    }
};
