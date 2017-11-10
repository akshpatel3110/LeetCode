/*
3sum = iteration + 2sum

[-1, -1, -1, 0, 1, 2, 2, 2, 4]
             i  l           r                   
  
[-1, 0, 1]
[-1, -1, 2]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 2) {
            return res;
        }
        
        sort(nums.begin(), nums.end());
        size_t i = 0;
        while (i < nums.size() - 2) {
            int target = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    
                    while (l < r && nums[l] == triplet[1])
                        ++l;
                    
                    while (l < r && nums[r] == triplet[2])
                        --r;
                }
            }
            
            int curNum = nums[i];
            while (i < nums.size() - 2 && nums[i] == curNum)
                ++i;
        }
        
        return res;
    }
};
