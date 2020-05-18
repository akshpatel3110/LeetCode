class Solution {
public:
    // Time: O(nlogn + nlogd) where d is nums.back() - nums.front()
    // Space: O(1)
    int pairs_less_than_or_equal(const vector<int> & nums, int m) {
        int count = 0;
        for (int i = 1, j = 0; i < nums.size(); ++i) {
            while (j < i && nums[i] - nums[j] > m)
                ++j;
            count += i - j;
        }
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        while (l < r) {
            int m = l + r >> 1;
            if (pairs_less_than_or_equal(nums, m) >= k)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
