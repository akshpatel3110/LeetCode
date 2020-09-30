class Solution {
public:
    // Time: O(n)
    // Space: O(logn)
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(i * 2 + 1) % (n | 1)]
        
        int n = nums.size();
        auto mid_ptr = nums.begin() + n / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr;
        for (int i = 0, j = 0, k = n - 1; j <= k;) {
            if (A(j) == mid) ++j;
            else if (A(j) < mid) swap(A(j), A(k--));
            else swap(A(i++), A(j++));
        }
    }
};
