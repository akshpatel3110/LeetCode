class Solution {
public:
    vector<int> t;
    
    // Time: O(nlogn)
    // Space: O(n)
    int reversePairs(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    
    int dfs(vector<int> & nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = dfs(nums, l, mid) + dfs(nums, mid + 1, r);
        for (int i = l, j = mid + 1; i <= mid; ++i) {
            while (j <= r && nums[i] > nums[j] * 2ll) ++j;
            res += j - (mid + 1);
        }
        
        // sort
        t.clear();
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) t.push_back(nums[i++]);
            else t.push_back(nums[j++]);
        }
        
        // only one of the following statement will be executed
        while (i <= mid) t.push_back(nums[i++]);
        while (j <= r) t.push_back(nums[j++]);
        
        // put the sorted result back to nums
        for (int i = l, j = 0; j < t.size(); ++i, ++j) nums[i] = t[j];
        return res;
    }
};
