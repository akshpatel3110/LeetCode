class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (n < 2 || nums.back() < 0 || nums.front() > 0)
            return {};
        
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0)
                break;
            
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i], j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        ++j;
                    
                    while (j < k && nums[k] == nums[k - 1])
                        --k;
                    
                    ++j;
                    --k;
                } else if (nums[j] + nums[k] < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};
