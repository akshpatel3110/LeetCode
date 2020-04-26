class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> min_last;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(min_last.begin(), min_last.end(), nums[i]);
            if (it != min_last.end())
                *it = nums[i];
            else
                min_last.push_back(nums[i]);
        }
        return min_last.size();
    }
};
