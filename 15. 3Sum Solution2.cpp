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
            
            for (int j = i + 1, k = nums.size() - 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= 0)
                    --k;
                
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
