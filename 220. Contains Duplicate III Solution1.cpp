class Solution {
public:
    // use long long to avoid integer overflow for nums[i] - t and nums[i] + t
    // Time: O(nlogk)
    // Space: O(k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        using LL = long long;
        multiset<LL> hash; 
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (i - j == k + 1)
                hash.erase(hash.find(nums[j++]));
                
            auto it = hash.lower_bound((LL)nums[i] - t);
            if (it != hash.end() && *it <= (LL)nums[i] + t)
                return true;
            
            hash.insert(nums[i]);
        }
        return false;
    }
};
