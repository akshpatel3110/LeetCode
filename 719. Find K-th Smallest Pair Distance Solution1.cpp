class Solution {
public:
    // Time: O(n ^ 2)
    // Space: O(N) or O(1)
    int smallestDistancePair(vector<int>& nums, int k) {
        int N = 1000000;
        vector<int> count(N + 1, 0);
        const size_t n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ++count[abs(nums[i] - nums[j])];
        
        int sum = 0;
        for (int i = 0; i <= N; ++i) {
            sum += count[i];
            if (sum >= k)
                return i;
        }
        
        return -1;
    }
};
