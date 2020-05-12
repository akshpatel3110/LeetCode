class Solution {
public:
    // Time: O(nlogk)
    // Space: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> m(nums.begin(), nums.begin() + k);
        auto mid = next(m.begin(), k / 2);
        int i = k;
        while (true) {
            res.push_back((*mid + (long long)*prev(mid, 1 - k % 2)) / 2.0);
            if (i == nums.size())
                return res;
            
            m.insert(nums[i]);
            if (nums[i] < *mid)
                --mid;
            
            if (nums[i - k] <= *mid)
                ++mid;
            m.erase(m.find(nums[i - k]));
            
            ++i;
        }
    }
};
