class Solution {
public:
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
        int pivot = nums[l], i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] <= pivot)
                --j;
            
            while (i < j && nums[i] >= pivot)
                ++i;
            
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        return i;
    }
};
