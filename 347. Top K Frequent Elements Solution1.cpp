class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto x : nums)
            ++hash[x];
        
        int n = nums.size();
        vector<int> q(n + 1);
        for (auto [x, c] : hash)
            ++q[c];
        
        int i = n, sum = 0;
        while (sum < k)
            sum += q[i--];
        
        vector<int> res;
        for (auto [x, c] : hash) {
            if (c > i)
                res.push_back(x);
        }
        return res;
    }
};
