class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> min_last;
        for (int i = 0; i < nums.size(); ++i) {
            int l = 0, r = min_last.size() - 1;
            while (l < r) {
                int m = l + (long long)r >> 1;
                if (min_last[m] >= nums[i])
                    r = m;
                else
                    l = m + 1;
            }
            if (min_last.size() && min_last[l] >= nums[i])
                min_last[l] = nums[i];
            else
                min_last.push_back(nums[i]);
        }
        return min_last.size();
    }
};
