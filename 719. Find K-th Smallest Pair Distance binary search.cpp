/*
Solution 1: counting sort
time O(n^2)
space O(max(nums))

Count the distances all pairs
Start with lowest distance, sum up all distances, find the first distance such that the sum >= k
[2, 3, 3, 5, 7]  k = 4

1 2 3 1 2 1 0 0  count
0 1 2 3 4 5 6 7  distance
    i

sum 6


Solution 2: binary search
time: O(nlog(max(n, nums)))
space: O(1)


sort nums O(nlogn)
find the smallest distance d such that at least k pairs have distances <= d
1. Given a distance d, find the number of pairs with distances <= d (two pointer) O(n)
2. binary search (upper bound) within 0 ~ (maxNum - minNum) O(log(max(nums))
For each distance given in subproblem 2:
    do subproblem one

i i + 1, ... j - 1, j

*/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const size_t n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l < r) {
            int count = 0;
            int m = l + (r - l) / 2;
            int j = 0;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= m)
                    ++j;
                
                count += j - i - 1;
            }
            
            if (count >= k)
                r = m;
            else
                l = m + 1;
        }
        
        return l;
        
    }
};
