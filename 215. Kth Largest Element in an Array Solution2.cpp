class Solution {
public:
    // Time: O(n + n / 2 + n / 4 + ...) = O(n)
    // Space: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == k - 1)
                return nums[pos];
            if (pos > k - 1)
                r = pos - 1;
            else
                l = pos + 1;            
        }
    }
    
    int partition(vector<int> & nums, int l, int r) {
        swap(nums[l], nums[l + rand() % (r - l + 1)]);
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] <= pivot)
                --r;
            
            nums[l] = nums[r];
            
            while (l < r && nums[l] >= pivot)
                ++l;
            
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};
