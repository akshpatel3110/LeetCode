class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i)
            p.emplace_back(nums[i], i);
        
        sort(p.begin(), p.end(), greater<pair<int, int>>());
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            auto & e = res[p[i].second];
            if (i == 0) e = "Gold Medal";
            else if (i == 1) e = "Silver Medal";
            else if (i == 2) e = "Bronze Medal";
            else e = to_string(i + 1);
        }
        return res;
    }
};
