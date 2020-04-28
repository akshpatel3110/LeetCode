class Solution {
public:
    // min_last[i] records the minimum last number for increasing sebsequence with length of i + 1
    int lengthOfLIS(vector<int>& nums) {
        vector<int> min_last;
        for (int num : nums) {
            auto it = lower_bound(min_last.begin(), min_last.end(), num);
            if (it != min_last.end())
                *it = num;
            else
                min_last.push_back(num);
        }
        return min_last.size();
    }
};
