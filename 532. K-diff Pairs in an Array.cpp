/*
Fix i, Move j

 [1, 1, 2, 2, 4, 4, 5, 5, 5, 6, 7, 8] k = 2 
                                i
                                      j
     
  j = max(i + 1, j)   
*/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int res = 0;
        sort(nums.begin(), nums.end());
        size_t i = 0;
        size_t j = 1;
        while (j < nums.size()) {
            j = max(i + 1, j);
            while (j < nums.size() && nums[j] - nums[i] < k)
                ++j;
            
            if (j < nums.size() && nums[j] - nums[i] == k)
                ++res;
            
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1])
                ++i;
        }
        return res;
    }
};
