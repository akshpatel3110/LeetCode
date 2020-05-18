class Solution {
public:
    // min distance: 0
    // max distance: N - 1
    // Time: O(n ^ 2 + N)
    // Space: O(N)
    int smallestDistancePair(vector<int>& nums, int k) {
        int N = 1000000;
        vector<int> count(N);
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                ++count[abs(nums[i] - nums[j])];
        
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += count[i];
            if (sum >= k)
                return i;
        }
        return -1;
    }
};
