/*
Solution 1: counting sort
time O(n^2)
space O(max(nums))

Count of the distances all pairs
Start with lower distance, sum up all distances, find the first distance such that the sum >= k
[2, 3, 3, 5, 7]  k = 4

1 2 3 1 2 1 0 0  count
0 1 2 3 4 5 6 7  index

sum 0


Solution 2: binary search
sort nums



*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int N = 1000000;
        vector<int> count(N + 1, 0);        
        const size_t n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
               ++count[abs(nums[j] - nums[i])];
        
        int sum = 0;
        for (int i = 0; i <= N; ++i) {
            sum += count[i];
            if (sum >= k) 
                return i;
        }
        return 0;        
    }
};
