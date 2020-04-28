class Solution {
public:
    // min_last[i] records the minimum last number for increasing sebsequence with length of i + 1
    int lengthOfLIS(vector<int>& nums) {
        vector<int> min_last;
        for (int num : nums) {
            int l = 0, r = min_last.size() - 1;
            while (l < r) {
                int m = l + (long long)r >> 1;
                if (min_last[m] >= num)
                    r = m;
                else
                    l = m + 1;
            }
            if (min_last.size() && min_last[l] >= num)
                min_last[l] = num;
            else
                min_last.push_back(num);
        }
        return min_last.size();
    }
};
